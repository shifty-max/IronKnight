// Copyright Maksym (Maxim) Khytra. 
// Transits palyer to next level when it overlaps 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelTransiotionVolume.generated.h"

UCLASS()
class IRONKNIGHT_API ALevelTransiotionVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelTransiotionVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Transition)
	class UBoxComponent* TransitionVolume;

	class UBillboardComponent* Billboard;

	//variable to save next level map name
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Transition)
	FName TransitionLevelName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//When player overlaps we change a map
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
