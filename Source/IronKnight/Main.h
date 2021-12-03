// Copyright Maksym (Maxim) Khytra. 
// Main character class. Also provides Save and Load game functionality throught FirstSaveGame class

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Main.generated.h"

UENUM(BlueprintType)
enum class EMovementStatus :uint8
{
	EMS_Normal UMETA(DisplayName="Normal"),
	EMS_Sprinting UMETA(DisplayName="Sprinting"),
	EMS_Dead UMETA(DisplayName = "Dead"),

	EMS_MAX UMETA(DisplayName = "DefaultMAX")

};

UENUM(BlueprintType)
enum class EStaminaStatus : uint8
{
	ESS_Normal UMETA(DisplayName = "Normal"),
	ESS_BelowMinimum UMETA(DisplayName = "BelowMinimum"),
	ESS_Exhausted UMETA(DisplayName = "Exhausted"),
	ESS_ExhaustedRecovering UMETA(DisplayName = "ExhaustedRecovering"),
	ESS_MAX UMETA(DisplayName = "DefaultMAX")
};

UCLASS()
class IRONKNIGHT_API AMain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain();

	//Have to set it to blueprint made from ItemStorage class to save Weapon when save game
	UPROPERTY(EditDefaultsOnly, Category = "SaveData")
	TSubclassOf<class AItemStorage> WeaponStorage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat)
	bool bHasCombatTarget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Anims)
	bool bAttack;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Anims)
	bool bBlock;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Anims)
	bool bMagicSpell;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat)
	FVector CombatTargetLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Controller)
	class AMainPlayerController* MainPlayerController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Anims)
	class UAnimMontage* InjuryMontage ;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Anims)
	class UAnimMontage* BlockMontage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Anims)
	TArray<UAnimMontage*> CombatMontageArray;

	int32 MontageID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Items)
	class AWearpon* EquipedWearpon;

	//Damage apply to enemy on every stage of combo
	float ComboDamage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Items)
	class AItem* OverlappingItem;

	//Using it only for debug
	TArray <FVector> PickupLocations;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Enums)
	EMovementStatus MovementStatus;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Enums)
	EStaminaStatus StaminaStatus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Running)
	float RunningSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Running)
	float SprintingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Running)
	float StaminaDrainRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Running)
	float MinSprintStamina;

	//how fast we turn automatically our character to an enemy
	float InterpSpeed;

	//if we turn automatically our character to an enemy
	bool bInterpToEnemy;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta=(AllowPrivateAcces = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAcces = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMatineeCameraShake> CamShake;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat)
	class AEnemy* CombatTarget;

	//base turn rate scale turning functions for the camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnUpRate;

	/*
	*
	*	PLAYER STATS
	*
	*/


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	float SpellDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	float Stamina;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	int32 Coins;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	int32 MaxCoins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	class UParticleSystem* HitParticles;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	//UParticleSystem* MainSpellParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Particles")
	class UParticleSystemComponent* MainSpellParticlesComponent;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
	//class UNiagaraSystem* MainSpellNiagara;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	class USoundCue* HitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	class USoundCue* InjurySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	class USoundCue* LastComboHitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	class USoundCue* SpellSound;

	bool bMovingForvard;
	bool bMovingRight;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	bool bNewSession;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<AEnemy> EnemyFilter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<class UDamageType> DamageTypeClass;

	FTimerHandle ComboTimer;
	FTimerHandle MagicTimer;

	float MaxComboTime;
	
	uint8 ComboCount;

	virtual void Jump() override;

protected:
	// Called when the gamesh starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Called for forward/backward moving
	void MoveForward(float value);

	//Called for side to side input
	void MoveRight(float value);

	//Turning uising mouse axes
	void Turn(float value);

	//Looking up/ down uising mouse axes
	void LookUp(float value);

	//Turning using Left/ Right keyboard keys
	// @param rate is a normalized rate, i.e. 1 means 100% turn 
	void TurnAtRate(float rate);

	//Turning using Up/ Down keyboard keys
	// @param rate is a normalized rate, i.e. 1 means 100% look up/down 
	void LookUpRate(float rate);

	void DecrementHealth(float Amount);

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable)
	void IncrementCoin(int32 Amount);

	UFUNCTION(BlueprintCallable)
	void IncrementHealth(float Amount);

	void Die();

	void SetEquipedWearpon(AWearpon* Wearpon);

	//Set MovementStatus aka runnign speed
	void SetMovementStatus(EMovementStatus Status);

	//Shift pressed Down for sprinting or Realeased for ordinary running
	void ShiftKeyDown();
	void ShiftKeyUp();
	bool bShiftKeyDown;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	FORCEINLINE void SetStaminaStatus(EStaminaStatus Status) { StaminaStatus = Status; }

	FORCEINLINE AWearpon* GetEquipedWearpon() { return EquipedWearpon; }
	FORCEINLINE void SetActiveOverlappingItem(AItem* Item) { OverlappingItem = Item; }

	FORCEINLINE void SetCombatTarget(AEnemy* Target) { CombatTarget = Target; }

	FORCEINLINE void SetHasCombatTarget(bool HasTarget) { bHasCombatTarget = HasTarget; }

	//Using this function mainly to calculate Enemy Rotator and later turn character to face an Enemy
	FRotator GetLookAtRotationYaw(FVector Target);

	//Only for DEBUG
	UFUNCTION(BlueprintCallable)
	void ShowPickupLocations();

	void LMBDown();
	void LMBUP();
	bool bLMBDown;

	void RMBDown();
	void RMBUP();
	bool bRMBDown;

	void MMBDown();
	void MMBUP();
	bool bMMBDown;

	void ESCDown();
	void ESCUp();
	bool bESCDown;

	void Attack();
	void Block();
	void MagicSpell();

	UFUNCTION(BlueprintCallable)
	void BlockEnd();

	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	UFUNCTION(BlueprintCallable)
	void MagicSpellEnd();

	//Using to disable Main Character moving abilies when it's dead
	bool CanMove(float Value);

	UFUNCTION(BlueprintCallable)
	void PlaySwingSound();

	void SetInterpToEnemy(bool bInterp);

	UFUNCTION(BlueprintCallable)
	void DeathEnd();

	void UpdateCombatTarget();

	void SwitchLevel(FName LevelName);

	UFUNCTION(BlueprintCallable)
	void SaveGame();

	UFUNCTION(BlueprintCallable)
	void LoadGame(bool SetPosition);

	UFUNCTION(BlueprintCallable)
	void LoadGameNoSwitch();

	void CameraShake(float ShakingMultiplier = 1.0f, float AlphaMax = 0.2f, float Duration = 0.3f, FLinearColor CamFadeColor = FLinearColor(1, 0.5, 0.5));
};
