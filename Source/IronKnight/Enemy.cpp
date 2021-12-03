// Copyright Maksym (Maxim) Khytra. 


#include "Enemy.h"
#include "Components/SphereComponent.h"
#include "AIController.h"
#include "Main.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GamePlayStatics.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Sound/SoundCue.h"
#include "Animation/AnimInstance.h"
#include "TimerManager.h"
#include "Components/CapsuleComponent.h"
#include "MainPlayerController.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AgroSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AgroSphere"));
	AgroSphere->SetupAttachment(GetRootComponent());
	AgroSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);
	AgroSphere->InitSphereRadius(600.0f);

	CombatSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CombatSphere"));
	CombatSphere->SetupAttachment(GetRootComponent());
	CombatSphere->InitSphereRadius(75.0f);

	CombatCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CombatCollision"));
	CombatCollision->SetupAttachment(GetMesh(), FName("EnemySocket"));

	bOverlappingCombatSphere = false;
	bStun = false;

	bHasValidTarget = false;

	Health = 75.f;
	MaxHealth = 100.f;
	Damage = 10.f;

	AttackAfterBlockTime = 1.2f;
	AttackMinTime = 0.5f;
	AttackMaxTime = 1.2f;

	CameraShake = 1.0f;
	CameraOpacityFade = 0.2;
	CameraColorFade = { 1.f, 0.5f, 0.5f };
	CameraFadeTiming = 0.3f;

	DissolveSpeed = 0.1f;
	DissolveStart = 1.f;
	DeathDelay = 3.f;

	EnemyMovementStatus = EEnemyMovementStatus::EMS_Idle;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	AIController = Cast<AAIController>(GetController());

	AgroSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::AgroSphereOnOverlapBegin);
	AgroSphere->OnComponentEndOverlap.AddDynamic(this, &AEnemy::AgroSphereOnOverlapEnd);

	CombatSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::CombatSphereOnOverlapBegin);
	CombatSphere->OnComponentEndOverlap.AddDynamic(this, &AEnemy::CombatSphereOnOverlapEnd);

	CombatCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::CombatOnOverlapBegin);
	CombatCollision->OnComponentEndOverlap.AddDynamic(this, &AEnemy::CombatOnOverlapEnd);

	CombatCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CombatCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CombatCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CombatCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//When overlapping begin a player is dected by an enemy and actor starts to move to a player
void AEnemy::AgroSphereOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && Alive() && !bStun)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			MoveToTarget(Main);
		}
	}
}

//When overlapping end a player is not visible to an enemy
void AEnemy::AgroSphereOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			bHasValidTarget = false;
			if (Main->CombatTarget == this)
			{
				Main->SetCombatTarget(nullptr);
			}
			Main->SetHasCombatTarget(false);
			Main->UpdateCombatTarget();

			//stop chasing of a player when he is out of agro sphere
			SetEnemyMovementStatus(EEnemyMovementStatus::EMS_Idle);
			if(AIController)
				AIController->StopMovement();
		}
	}
}

//When overlapping an enemy will attack a player
void AEnemy::CombatSphereOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && Alive())
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			bHasValidTarget = true;
			Main->SetCombatTarget(this);
			Main->SetHasCombatTarget(true);
			
			Main->UpdateCombatTarget();

			CombatTarget = Main;
			bOverlappingCombatSphere = true;

			//to make gameplay easier some random delay beteween attacks is made. It could be versatile, depending on game difficulty 
			float AttackTime = FMath::FRandRange(AttackMinTime, AttackMaxTime);
			GetWorldTimerManager().SetTimer(AttackTimer, this, &AEnemy::Attack, AttackTime, false, AttackTime);
		}
	}
}

//When overlapping ends an enemy is too far to attack a player
void AEnemy::CombatSphereOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherComp)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			bOverlappingCombatSphere = false;
			MoveToTarget(Main);
			CombatTarget = nullptr;

			//if overlapping ends it means a player mesh is too far to attack an emeny also
			if(Main->CombatTarget == this)
			{
				Main->SetCombatTarget(nullptr);
				Main->bHasCombatTarget = false;
				Main->UpdateCombatTarget();
			}
			if(Main->MainPlayerController)
			{
				USkeletalMeshComponent* MainMesh = Cast<USkeletalMeshComponent> (OtherComp);
				if (MainMesh)
					Main->MainPlayerController->RemoveEnemyHealthBar(); //try to set here Main->UpdateCOmbatTarget() insted
			}

			GetWorldTimerManager().ClearTimer(AttackTimer);
		}
	}
}

void AEnemy::MoveToTarget(class AMain* Target)
{
		SetEnemyMovementStatus(EEnemyMovementStatus::EMS_MoveToTarget);

	if (AIController)
	{
		FAIMoveRequest MoveRequest;
		MoveRequest.SetGoalActor(Target);
		MoveRequest.SetAcceptanceRadius(15.0f);

		FNavPathSharedPtr NavPath;

		AIController->MoveTo(MoveRequest, &NavPath);


		/* Debug Sphere to visualize the Enemy path
		TArray <FNavPathPoint> PathPoints = NavPath->GetPathPoints();

		for (auto Point : PathPoints)
		{
			FVector Location = Point.Location;

			UKismetSystemLibrary::DrawDebugSphere(this, Location + FVector(0.f, 0.f, 25.f), 55.f, 32, FLinearColor::Red, 1.f, 1.3f);
		}
		*/
	}
}

//Collision event for enemy weapon
void AEnemy::CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			if (!Main->bBlock)
			{
				if (Main->HitParticles)
				{

					const USkeletalMeshSocket* TipSocket = GetMesh()->GetSocketByName("TipSocket");
					if (TipSocket)
					{
						FVector SocketLocation = TipSocket->GetSocketLocation(GetMesh());
						UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Main->HitParticles, SocketLocation, FRotator(0.f), false);
					}

				}
				if (Main->HitSound)
				{
					UGameplayStatics::PlaySound2D(this, Main->HitSound);
				}
				if (DamageTypeClass)
				{
					UGameplayStatics::ApplyDamage(Main, Damage, AIController, this, DamageTypeClass);
					Main->CameraShake(CameraShake, CameraOpacityFade, CameraFadeTiming, CameraColorFade);
				}
			}

			//if attack is blocked nothing happens exept camera shake
			else
			{
				Main->CameraShake(CameraShake / 2, 0.f, 0.f, CameraColorFade);
			}
		}
	}
}


//Collision end event for enemy weapon
void AEnemy::CombatOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AEnemy::ActivateCollision()
{
	CombatCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AEnemy::DeactivateCollision()
{
	CombatCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEnemy::BlockCollision()
{
	CombatCollision->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
}

void AEnemy::AttackEnd()
{
	bAttacking = false;
	if (bOverlappingCombatSphere)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Attack End"));
		float AttackTime = FMath::FRandRange(AttackMinTime, AttackMaxTime);
		GetWorldTimerManager().SetTimer(AttackTimer, this, &AEnemy::Attack, AttackTime, false);
	}
}

void AEnemy::Attack()
{	
	if (Alive() && bHasValidTarget && !bStun)
	{
		if (AIController)
		{
			AIController->StopMovement();
			SetEnemyMovementStatus(EEnemyMovementStatus::EMS_Attacking);
		}
		if (!bAttacking)
		{
			bAttacking = true;
			UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
			if (AnimInstance && CombatMontage)
			{
				//Random attacks plays
				int32 Section = FMath::RandRange(0, 3);
				switch (Section)
				{
				case 0:
					AnimInstance->Montage_Play(CombatMontage, 1.f);
					AnimInstance->Montage_JumpToSection(FName("Attack_1"), CombatMontage);
					UE_LOG(LogTemp, Warning, TEXT("EnemY_Attack_1"));
					break;
				case 1:
					AnimInstance->Montage_Play(CombatMontage, 1.f);
					AnimInstance->Montage_JumpToSection(FName("Attack_2"), CombatMontage);
					UE_LOG(LogTemp, Warning, TEXT("EnemY_Attack_2"));
					break;
				case 2:
					AnimInstance->Montage_Play(CombatMontage, 1.f);
					AnimInstance->Montage_JumpToSection(FName("Attack_3"), CombatMontage);
					UE_LOG(LogTemp, Warning, TEXT("EnemY_Attack_3"));
					break;
				case 3:
					AnimInstance->Montage_Play(CombatMontage, 1.f);
					AnimInstance->Montage_JumpToSection(FName("Attack_4"), CombatMontage);
					UE_LOG(LogTemp, Warning, TEXT("EnemY_Attack_4"));
					break;
				default:
					;
				}
			}
			if (AttackSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, AttackSound, GetActorLocation());
			}
			if (SwingSound)
			{
				UGameplayStatics::PlaySound2D(this, SwingSound);
			}
			
		}
	}
}

void AEnemy::Blocked()
{
	if (CombatTarget)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		
		//check if a main charater set the block, if true diactivate weapon collisionand stop attack animation
		//call AttackEnd function with delay 
		if (CombatTarget->bBlock)
		{
			AnimInstance->Montage_Stop( 0.f, CombatMontage);
			DeactivateCollision();
			float AttackTime = FMath::FRandRange(AttackMinTime, AttackMaxTime);
			GetWorldTimerManager().SetTimer(AttackTimer, this, &AEnemy::AttackEnd, AttackAfterBlockTime, false);
		}
	}
}

void AEnemy::Stun()
{
	bStun = true;
	
	if (AIController)
	{
		AIController->StopMovement();
	}

	if (Health <= 0.f)
	{
		DeactivateCollision();
		return;
	}

	DeactivateCollision();
	CombatSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && CombatMontage)
	{
		AnimInstance->Montage_Play(CombatMontage, 0.25f);
		AnimInstance->Montage_JumpToSection("Stun", CombatMontage);
	
		if (StunParticles)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), StunParticles, GetActorLocation(), FRotator(0.0f), true);
		}
	}
}

void AEnemy::StunEnd()
{
	CombatSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	bStun = false;
}

float AEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	if (Health - DamageAmount <= 0.f)
	{
		//Check damage causer. If it is weapon an enmy won't explode immidiately, if it is spell he will
		AMain* Main = Cast<AMain>(DamageCauser);
		if (bStun && !Main)
		{
			bStun = false;
		}
		Health -= DamageAmount;
		Die(DamageCauser);
	}
	else
	{
		if (bStun)
		{
			StunEnd();
		}

		DeactivateCollision();
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance && CombatMontage)
		{
			AnimInstance->Montage_Play(CombatMontage, 0.4f);
			AnimInstance->Montage_JumpToSection("Injury", CombatMontage);
		}
		if(InjurySound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, InjurySound, GetActorLocation());
		}
		//AttackEnd();
		Health -= DamageAmount;
	}
	return DamageAmount;
}

void AEnemy::Dissolving()
{
	float DissolveParam; 
	DynamicDeathMaterial->GetScalarParameterValue(FName("Disolve"), DissolveParam);
	DynamicDeathMaterial->SetScalarParameterValue(FName("Disolve"), DissolveParam - DissolveSpeed);
}

void AEnemy::Die(AActor* DamageCauser)
{


	if (DeathParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation(), true);
	}

	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}

	if (DeathMaterial)
	{
		GetMesh()->SetMaterial(0, DeathMaterial);
		DynamicDeathMaterial = UMaterialInstanceDynamic::Create(DeathMaterial, GetMesh());
		GetMesh()->SetMaterial(0, DynamicDeathMaterial);
		// if Enemy killed by MainPlayer speel he dissolves imidiatelly to make explosion illusion
		if (bStun)
		{
			DissolveStart = 0.001f;
			DynamicDeathMaterial->SetScalarParameterValue(FName("Disolve"),0.85f);
		}
		GetWorldTimerManager().SetTimer(DeathTimer, this, &AEnemy::Dissolving, 0.1f, true, DissolveStart);
		//DynamicDeathMaterial->SetScalarParameterValue(FName("Disolve"), 0.f);
	}

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance)
	{
		AnimInstance->Montage_Play(CombatMontage, 0.6f);
		AnimInstance->Montage_JumpToSection(FName("Death"), CombatMontage);
	}

	SetEnemyMovementStatus(EEnemyMovementStatus::EMS_Dead);

	CombatCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AgroSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CombatSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	bAttacking = false;

	AMain* Main = Cast<AMain>(DamageCauser);

	//If enemy dead update target for Main character
	if (Main)
	{
		Main->UpdateCombatTarget();
	}
}

void AEnemy::DeathEnd()
{
	GetMesh()->bPauseAnims = true;
	GetMesh()->bNoSkeletonUpdate = true;

	//Dead enemy body disapears after dead
	GetWorldTimerManager().SetTimer(DeathTimer, this, &AEnemy::Disappear, DeathDelay);
}

//Checks if an enemy is alive, if not it can't make any harm to a player
bool AEnemy::Alive()
{
	return GetEnemyMovementStatus() != EEnemyMovementStatus::EMS_Dead;
}

//Enemy mesh disapears after death
void AEnemy::Disappear()
{
	Destroy();

}