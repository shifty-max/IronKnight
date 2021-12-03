// Copyright Maksym (Maxim) Khytra. 


#include "Main.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Wearpon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "Sound/SoundCue.h"
#include "Kismet/GamePlayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Enemy.h"
#include "MainPlayerController.h"
#include "FirstSaveGame.h"
#include "ItemStorage.h"
#include "FirstProjectGameModeBase.h"
#include "CustomGameInstance.h"
#include "Camera/PlayerCameraManager.h"
#include "TimerManager.h"
#include "particles/ParticleSystemComponent.h"


// Sets default values
AMain::AMain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	//Set size for collizion capsule
	GetCapsuleComponent()->SetCapsuleSize(33.3f, 88.0f);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	MainSpellParticlesComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SpellParticlesComponent"));
	MainSpellParticlesComponent->SetupAttachment(GetMesh(), FName("SpellSocket"));
	MainSpellParticlesComponent->ActivateSystem(false);
	
	//Set values for our turn rates input
	BaseTurnRate = 65.f;
	BaseTurnUpRate = 65.f;
	
	//don't roll the character when camera rotates, only the camera will rotate around the character
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	//configure character movment
	GetCharacterMovement()->bOrientRotationToMovement = true; //character rotates and moves	in direction of input
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.0f); // ... at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 650.f;
	GetCharacterMovement()->AirControl = 0.2f;

	//MainSpellParticles->SecondsBeforeInactive = 1.f;

	bHasCombatTarget = true;
	
	//Default Character values
	Health = 65.f;
	MaxHealth = 100.f;
	Stamina=120.f;
	MaxStamina = 150.f;
	Coins = 0;
	MaxCoins = 5;
	SpellDamage = 35.f;

	RunningSpeed = 650.0f;
	SprintingSpeed = 950.0f;

	StaminaDrainRate = 25.f;
	MinSprintStamina = 50.f;

	MaxComboTime = 1.5f;
	ComboCount = 0;
	MontageID = 0;



	//How fast Character turns to enemy when interacts with CombatSphere
	InterpSpeed = 15.f;
	bInterpToEnemy = false;

	bShiftKeyDown = false;
	bLMBDown = false;
	bRMBDown = false;
	bMMBDown = false;
	bESCDown = false;

	bBlock = false;
	bMovingForvard = false;
	bMovingRight = false;

	MovementStatus = EMovementStatus::EMS_Normal;
	StaminaStatus = EStaminaStatus::ESS_Normal;
}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();

	MainPlayerController = Cast<AMainPlayerController>(GetController());

	FString Map = GetWorld()->GetMapName();
	Map.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	
	//Need this to check NewGame bool. True if we start NewGame or false if Resume
	//from the SavedGame spot
	UCustomGameInstance* CustomGameInstance = Cast<UCustomGameInstance>(GetGameInstance());
	if (!CustomGameInstance->NewGame)
	{	
		UE_LOG(LogTemp, Warning, TEXT("No New Session"));
		LoadGameNoSwitch();

		//Remove mouse coursor from the screen
		if (MainPlayerController)
		{
			MainPlayerController->GameModeOnly();
		}
	}
	
}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MovementStatus == EMovementStatus::EMS_Dead)
		return;

	//Variable to exclude form Stamina and drain it every frame is Shift is down
	float DeltaStamina = StaminaDrainRate * DeltaTime;

	//Set movement speed according to Shift btn down and Stamina level
	switch (StaminaStatus)
	{
	case EStaminaStatus::ESS_Normal: 
		if (bShiftKeyDown)
		{
			if (Stamina - DeltaStamina <= MinSprintStamina)
			{
				SetStaminaStatus(EStaminaStatus::ESS_BelowMinimum);
				Stamina -= DeltaStamina;
			}
			else
				Stamina -= DeltaStamina;
			if (bMovingForvard || bMovingRight)
			{
				SetMovementStatus(EMovementStatus::EMS_Sprinting);
			}
			else
			{
				SetMovementStatus(EMovementStatus::EMS_Normal);
			}
		}
		else //if shift key up
		{
			if (Stamina + DeltaStamina >= MaxStamina)
				Stamina = MaxStamina;
			else
				Stamina += DeltaStamina;
			SetMovementStatus(EMovementStatus::EMS_Normal);
		}
		break;
	case EStaminaStatus::ESS_BelowMinimum:
		if (bShiftKeyDown)
		{
			if (Stamina - DeltaStamina <= 0.f)
			{
				SetStaminaStatus(EStaminaStatus::ESS_Exhausted);
				Stamina = 0.f;
				SetMovementStatus(EMovementStatus::EMS_Normal);
			}
			else
			{
				Stamina -= DeltaStamina;
				if (bMovingForvard || bMovingRight)
				{
					SetMovementStatus(EMovementStatus::EMS_Sprinting);
				}
				else
				{
					SetMovementStatus(EMovementStatus::EMS_Normal);
				}
			}
		}
		else //shift key is up
		{
			if (Stamina + DeltaStamina >= MinSprintStamina)
			{
				SetStaminaStatus(EStaminaStatus::ESS_Normal);
				Stamina += DeltaStamina;
			}
			else
				Stamina += DeltaStamina;
			SetMovementStatus(EMovementStatus::EMS_Normal);
		}
		break;
	case EStaminaStatus::ESS_Exhausted:
		if (bShiftKeyDown)
		{
			Stamina = 0.0f;
		}
		else //if shift key is up
		{
			SetStaminaStatus(EStaminaStatus::ESS_ExhaustedRecovering);
			Stamina += DeltaStamina;
		}
		SetMovementStatus(EMovementStatus::EMS_Normal);
		break;
	case EStaminaStatus::ESS_ExhaustedRecovering:
		if (Stamina + DeltaStamina >= MinSprintStamina)
		{
			SetStaminaStatus(EStaminaStatus::ESS_Normal);
			Stamina += DeltaStamina;
		}
		else
		{
			Stamina += DeltaStamina;
		}
		SetMovementStatus(EMovementStatus::EMS_Normal);
		break;
	default:
		;
	}
	
	//Set Character roation and interpolate his look directly at an enemy to make easier combat
	if (bInterpToEnemy && CombatTarget)
	{
		FRotator LookAtYaw = GetLookAtRotationYaw(CombatTarget->GetActorLocation());
		FRotator InterpRotation = FMath::RInterpTo(GetActorRotation(), LookAtYaw, DeltaTime, InterpSpeed);

		SetActorRotation(InterpRotation);
	}

	//Get Enemy Location to pass it to MainPlayerCOntroller and generate EnemyHealthBar
	if (CombatTarget)
	{
		CombatTargetLocation = CombatTarget->GetActorLocation();
		if (MainPlayerController)
		{
			MainPlayerController->EnemyLocation = CombatTargetLocation;
		}
	}

}

//Using this function mainly to calculate Enemy Rotator and later turn character to face an Enemy
FRotator AMain::GetLookAtRotationYaw(FVector Target)
{
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Target);
	return FRotator(0.f, LookAtRotation.Yaw, 0.f);
}

// Called to bind functionality to input
void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMain::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMain::ShiftKeyDown);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMain::ShiftKeyUp);

	PlayerInputComponent->BindAction("ESC", IE_Pressed, this, &AMain::ESCDown);
	PlayerInputComponent->BindAction("ESC", IE_Released, this, &AMain::ESCUp);

	PlayerInputComponent->BindAction("LMB", IE_Pressed, this, &AMain::LMBDown);
	PlayerInputComponent->BindAction("LMB", IE_Released, this, &AMain::LMBUP);

	PlayerInputComponent->BindAction("RMB", IE_Pressed, this, &AMain::RMBDown);
	PlayerInputComponent->BindAction("RMB", IE_Released, this, &AMain::RMBUP);

	PlayerInputComponent->BindAction("MMB", IE_Pressed, this, &AMain::MMBDown);
	PlayerInputComponent->BindAction("MMB", IE_Released, this, &AMain::MMBUP);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMain::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMain::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMain::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AMain::LookUp);

	PlayerInputComponent->BindAxis("TurnRate", this, &AMain::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMain::LookUpRate);
}

//Using to disable Main Character moving abilies when it's dead
bool AMain::CanMove(float Value)
{	
	if (MainPlayerController)
	{
		return (Value != 0.0f) 
		&& (!bAttack) && (!bBlock) && (!bMagicSpell) && (MovementStatus != EMovementStatus::EMS_Dead
		&& !MainPlayerController->bPauseMenuVisible);
	}
	return false;
}


void AMain::MoveForward(float value)
{
	bMovingForvard = false;
	if (CanMove(value))
	{
		//find which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);

		bMovingForvard = true;
	}
}


void AMain::MoveRight(float value)
{
	bMovingRight = false;
	if (CanMove(value))
	{
		//find which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
		bMovingRight = true;
	}
}

//Turning uising mouse axes
void AMain::Turn(float value)
{
	if (CanMove(value))
	{
		AddControllerYawInput(value);
	}
}

//Looking up/ down uising mouse axes
void AMain::LookUp(float value)
{
	if (CanMove(value))
	{
		AddControllerPitchInput(value);
	}
}

void AMain::Jump()
{
	if (MainPlayerController)
		if (MainPlayerController->bPauseMenuVisible)
			return;

	if (MovementStatus != EMovementStatus::EMS_Dead)
		Super::Jump();

}

//Turning using Left/ Right keyboard keys
void AMain::TurnAtRate(float rate)
{
	AddControllerYawInput(rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

//Turning using Up/ Down keyboard keys
void AMain::LookUpRate(float rate)
{
	AddControllerPitchInput(rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMain::DecrementHealth(float Amount)
{
	if (Health - Amount <= 0.0f)
	{
		Health -= Amount;
		Die();
	}
	else
		Health -= Amount;
}

void AMain::IncrementCoin(int32 Amount)
{
	Coins += Amount;
}

void AMain::IncrementHealth(float Amount)
{
	if (Health + Amount >= MaxHealth)
	{
		Health = MaxHealth;
	}
	else
	{
		Health += Amount;
	}
}

//When teh Character dies we play Death animation and set MovementStatus to Dead
void AMain::Die()
{
	if (MovementStatus == EMovementStatus::EMS_Dead)
		return;
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && InjuryMontage)
	{
		AnimInstance->Montage_Play(InjuryMontage, 1.0f);
		AnimInstance->Montage_JumpToSection(FName("Death"), InjuryMontage);
	}
	SetMovementStatus(EMovementStatus::EMS_Dead);
}

//After we palyed animation and set Movement status in Die() we disable all animations
//Use it  in Animation BP
void AMain::DeathEnd()
{
	GetMesh()->bPauseAnims = true;
	GetMesh()->bNoSkeletonUpdate = true;
	SwitchLevel(FName("Level_ninja_1"));
}

void AMain::SetMovementStatus(EMovementStatus Status)
{
	MovementStatus = Status;
	if (MovementStatus == EMovementStatus::EMS_Sprinting)
		GetCharacterMovement()->MaxWalkSpeed = SprintingSpeed;
	else
		GetCharacterMovement()->MaxWalkSpeed = RunningSpeed;
}

void AMain::ShiftKeyDown()
{
	bShiftKeyDown = true;
}

void AMain::ShiftKeyUp()
{
	bShiftKeyDown = false;
}

//Only for DEBUG. Shows Pickups
void AMain::ShowPickupLocations()
{
	for (int32 i = 0; i < PickupLocations.Num(); i++)
	{
		UKismetSystemLibrary::DrawDebugSphere(this, PickupLocations[i] + FVector(0.f, 0.f, 75.f), 35.f, 12, FLinearColor::Red, 25.f, 0.7f);
	}
	
	UKismetSystemLibrary::DrawDebugSphere(this, GetActorLocation() + FVector(0.f, 0.f, 75.f), 55.f, 32, FLinearColor::Red, 5.f, 0.3f);
}

void AMain::LMBDown()
{
	UE_LOG(LogTemp, Warning, TEXT("LMBDown"));
	bLMBDown = true;

	if (MovementStatus == EMovementStatus::EMS_Dead)
		return;

	if (MainPlayerController)
		if (MainPlayerController->bPauseMenuVisible)
			return;

	//If overlapping with item and press LMB we equip our Character with it
	//Possible to add interaction with other actors in future like swithces, etc...
	if (OverlappingItem)
	{
		AWearpon* Wearpon = Cast<AWearpon>(OverlappingItem);
		if (Wearpon)
		{
			Wearpon->Equip(this);
			SetActiveOverlappingItem(nullptr);
		}
	}

	//If Character has a weapon he can attack
	else if (EquipedWearpon && !bMagicSpell && !bBlock && !bAttack)
	{
		Attack();
	}
}

void AMain::LMBUP()
{
	UE_LOG(LogTemp, Warning, TEXT("LMBUp"));
	bLMBDown = false;
}

//Call PauseMenu wwith ESC, in GameEditor we also can use Q key to call it
void AMain::ESCDown()
{
	bESCDown = true;

	if (MainPlayerController)
	{
		MainPlayerController->TogglePauseMenu();
	}
}

void AMain::ESCUp()
{
	bESCDown = false;
}

void AMain::Attack()
{
	if (!bAttack &&!bBlock && (MovementStatus != EMovementStatus::EMS_Dead))
	{
		bAttack = true;
		SetInterpToEnemy(true);

		// If new combo started we randomly chose index for CombatMontageArray
		if(ComboCount == 0)
		{
			MontageID = FMath::RandRange(0, (CombatMontageArray.Num()-1));
		}

		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance && CombatMontageArray[MontageID] )
		{
			//Check if character is in the air we use only one specific attack
			if (GetMovementComponent()->IsFalling())
			{
				ComboDamage = EquipedWearpon->Damage*2;
				AnimInstance->Montage_Play(CombatMontageArray[0],0.7f);
				AnimInstance->Montage_JumpToSection(FName("Attack_3"), CombatMontageArray[0]);
				return;
			}

			//Check again if we strart new combo because combo time passed or previuos combo was finished
			if (GetWorldTimerManager().GetTimerElapsed(ComboTimer) <= 0.f || ComboCount == 0)
			{

				//Set Damage to the essential value
				ComboDamage = EquipedWearpon->Damage;
				AnimInstance->Montage_Play(CombatMontageArray[MontageID], 1.f);
				AnimInstance->Montage_JumpToSection(FName("Attack_1"), CombatMontageArray[MontageID]);
				ComboCount = 1;
				GetWorldTimerManager().SetTimer(ComboTimer, MaxComboTime, false);
			}

			//if else we continue to attack with next combo move
			else
			{
				switch (ComboCount)
				{
				case 1:
					AnimInstance->Montage_Play(CombatMontageArray[MontageID], 1.f);
					AnimInstance->Montage_JumpToSection(FName("Attack_2"), CombatMontageArray[MontageID]);
					GetWorldTimerManager().SetTimer(ComboTimer, MaxComboTime, false);

					// Increase damage
					ComboDamage *= 1.3;
					ComboCount++;
					break;
				case 2:
					AnimInstance->Montage_Play(CombatMontageArray[MontageID], 1.f);
					AnimInstance->Montage_JumpToSection(FName("Attack_3"), CombatMontageArray[MontageID]);

					// Increase damage even more
					ComboDamage *= 1.5;
					GetWorldTimerManager().SetTimer(ComboTimer, MaxComboTime, false);
					if(LastComboHitSound)
					{
						UGameplayStatics::PlaySound2D(this, LastComboHitSound);
					}
					ComboCount = 0;
					break;
				default:
					;
				}
			}
		}
	}
}

//Use it in Animation BP
void AMain::AttackEnd()
{
	bAttack = false;
	SetInterpToEnemy(false);

	//***
	//If Uncoment this lines character will attack enemies always till button is pressed
	//**********************
	//if (bLMBDown)
	//{
	//	Attack();
	//}
	//**********************
}

void AMain::RMBDown()
{
	bRMBDown = true;

	if (MovementStatus == EMovementStatus::EMS_Dead)
		return;

	if (MainPlayerController)
		if (MainPlayerController->bPauseMenuVisible)
			return;

	//block only if character doesn't attack his enemies
	if (!bMagicSpell && !bAttack)
	{
		Block();
	}
}

void AMain::RMBUP()
{
	bRMBDown = false;
	BlockEnd();
}

void AMain::Block()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && BlockMontage && EquipedWearpon)
	{
		//we need switch here to start with a first animation when character sets up block
		//and if right mouse button is down plays second loopes animation he still stays in that pose
		switch (bBlock)
		{
		case 0:
			AnimInstance->Montage_Play(BlockMontage, 1.65f);
			AnimInstance->Montage_JumpToSection(FName("Block_1"), BlockMontage);
			
			//set this to true, next time we will play second animation
			bBlock = true;
			break;
		case 1:
			AnimInstance->Montage_Play(BlockMontage, 1.f);
			AnimInstance->Montage_JumpToSection(FName("Block_2"), BlockMontage);
			break;
		}
		bBlock = true;
		bAttack = false;
	}
}

void AMain::BlockEnd()
{
	if (!bRMBDown)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

		// play first block animation in reverse to back in an idle animation
		if (AnimInstance && BlockMontage && EquipedWearpon)
		{
			AnimInstance->Montage_Play(BlockMontage, -1.f);
			UE_LOG(LogTemp, Warning, TEXT("Play Montage,  %d"), bBlock);
			AnimInstance->Montage_JumpToSection(FName("Block_1"), BlockMontage);
		}
		bBlock = false;

		if (bMagicSpell)
		{
			MagicSpellEnd();
		}

		if (bAttack)
		{
			AttackEnd();
		}

		UE_LOG(LogTemp, Warning, TEXT("Block ends, %d, %d, %d"), bBlock, bMagicSpell, bAttack);
	}

	//if right mouse button isn't pressed chracter's secon part looped animation play
	else
	{
		bBlock = true;
		Block();
		UE_LOG(LogTemp, Warning, TEXT("Block ends, %d"), bBlock);
	}
}

// Medium Mouse Button to call magic
void AMain::MMBDown()
{
	bMMBDown = true;

	if (MovementStatus == EMovementStatus::EMS_Dead)
		return;

	if (MainPlayerController)
		if (MainPlayerController->bPauseMenuVisible)
			return;

	if (!bMagicSpell && !bBlock &&!bAttack)
	{
		MagicSpell();
	}
}

void AMain::MMBUP()
{
	bMMBDown = false;
}

// The magic spell is going in CombatMontageArray[0] !!!!!
void AMain::MagicSpell()
{
	
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && CombatMontageArray[0] && Coins >= 1)
	{
		bMagicSpell = true;
		AnimInstance->Montage_Play(CombatMontageArray[0], 1.f);
		AnimInstance->Montage_JumpToSection(FName("MagicSpell"), CombatMontageArray[0]);
		
		if (MainSpellParticlesComponent)
		{
			MainSpellParticlesComponent->ActivateSystem(true);

		}

		if (SpellSound)
		{
			UGameplayStatics::PlaySound2D(this, SpellSound);
		}


		//Create the array with overlapping enemies
		TArray<AActor*>OverlappingActors;
		GetOverlappingActors(OverlappingActors, EnemyFilter);

		if (OverlappingActors.Num() == 0)
		{
			return;
		}

		//gives damage to all overlapping enemies
		else
		{
			for (auto Actor : OverlappingActors)
			{
				AEnemy* Enemy = Cast<AEnemy>(Actor);
				if (Enemy)
				{
					Enemy->bStun = true;
					UGameplayStatics::ApplyDamage(Enemy, SpellDamage * Coins, MainPlayerController, this, DamageTypeClass);
					Enemy->Stun();
				}
			}
		}
		Coins = 0.f;
	}
}

void AMain::MagicSpellEnd()
{
	MainSpellParticlesComponent->Deactivate();

	bMagicSpell = false;
	UE_LOG(LogTemp, Warning, TEXT("Magic spee ends, %d"), bMagicSpell);

}



//Use it in Animation BP
void AMain::PlaySwingSound()
{
	if(EquipedWearpon->SwingSound)
	{
		UGameplayStatics::PlaySound2D(this, EquipedWearpon->SwingSound);
	}
}

//Check bInterpToEnemy. Can use it when implement difficulty level, for example
void AMain::SetInterpToEnemy(bool bInterp)
{
	bInterpToEnemy = bInterp;
}

float AMain::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	// if after hit there is no health left the character dies
	if (Health - DamageAmount <= 0.0f)
	{
		Health -= DamageAmount;
		Die();
		if (DamageCauser)
		{
			AEnemy* Enemy = Cast<AEnemy>(DamageCauser);
			if (Enemy)
				Enemy->bHasValidTarget = false;
		}
	}

	else
	{
		//if character bloks an enemy hit tehre is no damage, we exit this function
		if (bBlock)
		{
			return 0;
		}

		//normally if chracter isn't dead or didn't block the hit he got injury
		//and take injury animation plays
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance && InjuryMontage)
		{
			bAttack = false;
			bBlock = false;

			int32 Section = FMath::RandRange(0, 1);
			switch (Section)
			{
			case 0:
				AnimInstance->Montage_Play(InjuryMontage, 0.9f);
				AnimInstance->Montage_JumpToSection(FName("Injury_1"), InjuryMontage);
				UE_LOG(LogTemp, Warning, TEXT("Injury_1"));
				break;
			case 1:
				AnimInstance->Montage_Play(InjuryMontage, 0.9);
				AnimInstance->Montage_JumpToSection(FName("Injury_2"), InjuryMontage);
				UE_LOG(LogTemp, Warning, TEXT("Injury_2"));
				break;
			default:
				;
			}
			
		}
		Health -= DamageAmount;
	}
		return DamageAmount;
}


void AMain::UpdateCombatTarget()
{
	//Creating TArray of overlapping enemies
	TArray<AActor*>OverlappingActors;
	GetOverlappingActors(OverlappingActors, EnemyFilter);

	if (OverlappingActors.Num() == 0)
	{
		if (MainPlayerController)
			MainPlayerController->RemoveEnemyHealthBar();
		return;
	}

	//chosing closest enemy
	AEnemy* ClosestEnemy = Cast<AEnemy>(OverlappingActors[0]);
	if (ClosestEnemy)
	{
		FVector Location = GetActorLocation();
		float MinDistance = (ClosestEnemy->GetTargetLocation() - Location).Size();

		for (auto Actor : OverlappingActors)
		{
			AEnemy* Enemy = Cast<AEnemy>(Actor);
			if (Enemy)
			{
				float DistanceToActor = (Enemy->GetActorLocation() - Location).Size();
				if (DistanceToActor < MinDistance)
				{
					MinDistance = DistanceToActor;
					ClosestEnemy = Enemy;
				}
			
			}
		}
		if (MainPlayerController)
		{
			MainPlayerController->DisplayEnemyHealthBar();
		}
		SetCombatTarget (ClosestEnemy);
		bHasCombatTarget = true;
	}
}

//Switch Level when interact with Level Transiotion Volume
void AMain::SwitchLevel(FName LevelName)
{
	UWorld* World = GetWorld();
	if (World)
	{
		FString CurrentLevel = World->GetMapName();
		FName CurrentLevelName(*CurrentLevel);

		//Switching Levelonly if it is not teh same map
		if (CurrentLevelName != LevelName || MovementStatus == EMovementStatus::EMS_Dead)
		{
			UGameplayStatics::OpenLevel(World, LevelName);
		}
	}
	
}

void AMain::SaveGame()
{
	UFirstSaveGame* SaveGameInstance = Cast <UFirstSaveGame>(UGameplayStatics::CreateSaveGameObject(UFirstSaveGame::StaticClass()));

	SaveGameInstance->CharacterStats.Health = Health;
	SaveGameInstance->CharacterStats.MaxHealth = MaxHealth;
	SaveGameInstance->CharacterStats.Stamina = Stamina;
	SaveGameInstance->CharacterStats.MaxStamina = MaxStamina;
	SaveGameInstance->CharacterStats.Coins = Coins;
	SaveGameInstance->CharacterStats.Location = GetActorLocation();
	SaveGameInstance->CharacterStats.Rotation = GetActorRotation();
	
	FString MapName = GetWorld()->GetMapName();
	MapName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	UE_LOG(LogTemp, Warning, TEXT("Map name:%s"), *MapName);

	SaveGameInstance->CharacterStats.LevelName = MapName;

	if (EquipedWearpon)
	{
		SaveGameInstance->CharacterStats.WeaponName = EquipedWearpon->Name;
	}

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->PLayerName, SaveGameInstance->UserIndex);
	
}

void AMain::LoadGame(bool SetPosition)
{
	UFirstSaveGame* LoadGameInstance = Cast <UFirstSaveGame>(UGameplayStatics::CreateSaveGameObject(UFirstSaveGame::StaticClass()));

	LoadGameInstance = Cast<UFirstSaveGame> (UGameplayStatics::LoadGameFromSlot(LoadGameInstance->PLayerName, LoadGameInstance->UserIndex));

	Health = LoadGameInstance->CharacterStats.Health;
	MaxHealth = LoadGameInstance->CharacterStats.MaxHealth;
	Stamina = LoadGameInstance->CharacterStats.Stamina;
	MaxStamina = LoadGameInstance->CharacterStats.MaxStamina;
	Coins = LoadGameInstance->CharacterStats.Coins;

	//check if we have have created blueprint from ItemStorage class
	if (WeaponStorage)
	{
		AItemStorage* Weapons = GetWorld()->SpawnActor<AItemStorage>(WeaponStorage);
		if (Weapons)
		{
			FString WeaponName = LoadGameInstance->CharacterStats.WeaponName;

			if(Weapons->WeaponMap.Contains(WeaponName) && WeaponName != TEXT(""))
			{
				AWearpon* WeaponToEquip = GetWorld()->SpawnActor<AWearpon>( Weapons->WeaponMap[WeaponName]);
				WeaponToEquip->Equip(this);
			}
		}
	}

	//We can SetPosition = true to save player position or set it to false to start a level from a start
	if (SetPosition)
	{
		SetActorLocation(LoadGameInstance->CharacterStats.Location);
		SetActorRotation(LoadGameInstance->CharacterStats.Rotation);
	}

	SetMovementStatus(EMovementStatus::EMS_Normal);
	GetMesh()->bPauseAnims = false;
	GetMesh()->bNoSkeletonUpdate = false;

	if (LoadGameInstance->CharacterStats.LevelName != TEXT(""))
	{
		FName LevelName (*LoadGameInstance->CharacterStats.LevelName);

		SwitchLevel(LevelName);
	}
}

//Same as LoadGame() but doesn't switch the map
void AMain::LoadGameNoSwitch()
{
	UFirstSaveGame* LoadGameInstance = Cast <UFirstSaveGame>(UGameplayStatics::CreateSaveGameObject(UFirstSaveGame::StaticClass()));

	LoadGameInstance = Cast<UFirstSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->PLayerName, LoadGameInstance->UserIndex));

	Health = LoadGameInstance->CharacterStats.Health;
	MaxHealth = LoadGameInstance->CharacterStats.MaxHealth;
	Stamina = LoadGameInstance->CharacterStats.Stamina;
	MaxStamina = LoadGameInstance->CharacterStats.MaxStamina;
	Coins = LoadGameInstance->CharacterStats.Coins;

	if (WeaponStorage)
	{
		AItemStorage* Weapons = GetWorld()->SpawnActor<AItemStorage>(WeaponStorage);
		if (Weapons)
		{
			FString WeaponName = LoadGameInstance->CharacterStats.WeaponName;

			if (Weapons->WeaponMap.Contains(WeaponName))
			{
				AWearpon* WeaponToEquip = GetWorld()->SpawnActor<AWearpon>(Weapons->WeaponMap[WeaponName]);
				WeaponToEquip->Equip(this);
			}
		}
	}
	SetActorLocation(LoadGameInstance->CharacterStats.Location);
	SetActorRotation(LoadGameInstance->CharacterStats.Rotation);

	SetMovementStatus(EMovementStatus::EMS_Normal);
	GetMesh()->bPauseAnims = false;
	GetMesh()->bNoSkeletonUpdate = false;
}

//Camera shake functionality
void AMain::CameraShake(float ShakingMultiplier, float AlphaMax, float Duration, FLinearColor CamFadeColor)
{
	MainPlayerController->ClientStartCameraShake(CamShake, ShakingMultiplier);
	MainPlayerController->PlayerCameraManager->StartCameraFade(AlphaMax, 0.001f, Duration, CamFadeColor, false, false);
}

void AMain::SetEquipedWearpon(AWearpon* Wearpon)
{
	EquipedWearpon = Wearpon;
	ComboDamage = Wearpon->Damage;
}