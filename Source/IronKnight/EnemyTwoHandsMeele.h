// Copyright Maksym (Maxim) Khytra. 
// Class of an enemy with two meele hands, derived from AEnemy class

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "EnemyTwoHandsMeele.generated.h"

/**
 * 
 */
UCLASS()
class IRONKNIGHT_API AEnemyTwoHandsMeele : public AEnemy
{
	GENERATED_BODY()

public:
	
	AEnemyTwoHandsMeele();

	//Weapon collision for second hand when overlaps by a player he loosing health
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	UBoxComponent* CombatCollisionRight;

protected:
	virtual void BeginPlay() override;

public:

	//Activate collision for werpon when plays attack animation and finds apropriate anim note
	UFUNCTION(BlueprintCallable)
	void ActivateCollisionRight();

	//Dectivate collision for werpon when attack animation is almost finished and finds apropriate anim note
	UFUNCTION(BlueprintCallable)
	void DeactivateCollisionRight();

	UFUNCTION(BlueprintCallable)
	void BlockCollisionRight();

	virtual void Die(AActor* DamageCauser);

	virtual void CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
