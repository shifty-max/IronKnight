// Copyright Maksym (Maxim) Khytra. 
// It was created to store weapon with SaveGame() function.
// Wearpon is a pointer, so we can't save it in a variable.
// So the best way is to create Blueprint derived from this C++ file
// and add TMap of all available Weapons and Items.
// Generally, this actor class contains only TMap

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemStorage.generated.h"

UCLASS()
class IRONKNIGHT_API AItemStorage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemStorage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	//We declare TMap hastable to save weapons and items
	UPROPERTY(EditDefaultsOnly, Category = "SaveData")
	TMap<FString, TSubclassOf<class AWearpon>> WeaponMap;

};
