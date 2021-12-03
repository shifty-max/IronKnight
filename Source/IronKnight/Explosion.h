// Copyright Maksym (Maxim) Khytra. 
// Actor brings harm to player and destroy itself when they overlapping

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Explosion.generated.h"

/**
 * 
 */
UCLASS()
class IRONKNIGHT_API AExplosion : public AItem
{
	GENERATED_BODY()

public:
	AExplosion();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<UDamageType> DamageTypeClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Damage)
	float Damage;

public:

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
};
