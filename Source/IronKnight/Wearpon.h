// Copyright Maksym (Maxim) Khytra. 
// Weapon Class

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Wearpon.generated.h"

UENUM(BlueprintType)
enum class EWearponState : uint8
{
	EWS_Pickup UMETA(DisplayName = "Pickup"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Max UMETA(DisplayName = "DefaultMax")
};

/**
 * 
 */
UCLASS()
class IRONKNIGHT_API AWearpon : public AItem
{
	GENERATED_BODY()

public:
	AWearpon();

	//Weapon name for saving game functions
	UPROPERTY(EditDefaultsOnly, Category = "SavedData")
	FString Name;

	//Weapon state to know if it was picked up or was equiped
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
	EWearponState WearponState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Particles")
	bool bWeaponParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Sound")
	class USoundCue* OnEquipSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Sound")
	USoundCue* SwingSound;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Skeletal Mesh")
	class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Combat")
	class UBoxComponent* CombatCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Combat")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Combat")
	TSubclassOf<UDamageType> DamageTypeClass;

	//Need it for ApplyDamage function
	AController* WeaponInstigator;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void CombatOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Need it for animation notifiers
	UFUNCTION(BlueprintCallable)
	void ActivateCollision();

	//Need it for animation notifiers
	UFUNCTION(BlueprintCallable)
	void DeactivateCollision();
	
	//when player picks up a weapon
	void Equip(class AMain* Character);

	//Need pass controller to provide damage
	FORCEINLINE void SetInstigator(AController* Inst) { WeaponInstigator = Inst; }

	FORCEINLINE void SetWeraponState(EWearponState State) { WearponState = State; }
	FORCEINLINE EWearponState GetWeraponState() { return WearponState; }
	
protected:
	virtual void BeginPlay() override;

};
