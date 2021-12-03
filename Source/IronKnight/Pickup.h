// Copyright Maksym (Maxim) Khytra. 
// Class provides pickup as coins or other items for scores collection

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class IRONKNIGHT_API APickup : public AItem
{
	GENERATED_BODY()
public:
	APickup();

	//How many coins player gets when pick up certain unit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin")
	int32 CoinCount;

public:

	UFUNCTION(BlueprintImplementableEvent, Category ="Pickup")
	void OnPickupBP(class AMain* MainCharacter);

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
};
