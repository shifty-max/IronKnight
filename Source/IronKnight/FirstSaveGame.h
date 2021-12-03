// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FirstSaveGame.generated.h"

//Struct for saving all needed player's parameters and map name
USTRUCT(BlueprintType)
struct FCharactesStats
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	float Health;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	float Stamina;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	float MaxStamina;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	int32 Coins;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FVector Location;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FRotator Rotation;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FString WeaponName;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FString LevelName;
};

/**
 * 
 */
UCLASS()
class IRONKNIGHT_API UFirstSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UFirstSaveGame();

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString PLayerName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FCharactesStats CharacterStats;
	
	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;
};