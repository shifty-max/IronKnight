// Copyright Maksym (Maxim) Khytra.
// Triger Volume class, activates VFX and SFX vhen overlapping, can be delayed trought timer

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FXVolumeTrigger.generated.h"

UCLASS()
class IRONKNIGHT_API AFXVolumeTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFXVolumeTrigger();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Triger Volume")
	class UBoxComponent* TrigerBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triger Volume")
	class UParticleSystem* FXParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triger Volume")
	class USoundCue* SFXCue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triger Volume")
	float ActivationDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triger Volume")
	float Frequency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triger Volume")
	bool bLooped;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triger Volume")
	bool bActivateOnce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triger Volume")
	bool bCameraShake;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	FVector FXPoint;

	class UBillboardComponent* Billboard;

	FTimerHandle DelayTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ActivateFX();

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
