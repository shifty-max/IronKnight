// Copyright Maksym (Maxim) Khytra. 

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class IRONKNIGHT_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UCustomGameInstance();
	
	//Passes palayer choise if he selected NewGame or LoadGame in Menu
	UPROPERTY(BlueprintReadWrite, Category = "Menu")
	bool NewGame;
	
};
