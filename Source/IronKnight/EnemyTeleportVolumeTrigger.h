// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FXVolumeTrigger.h"
#include "EnemyTeleportVolumeTrigger.generated.h"


/**
 * 
 */
UCLASS()
class IRONKNIGHT_API AEnemyTeleportVolumeTrigger : public AFXVolumeTrigger
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawning)
	TSubclassOf <class AEnemy> Enemy;

public:

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
