// Copyright Maksym (Maxim) Khytra. 
// Simple Damage Volume class. Includes damage sound for more interactive experience than native Pain Causer volume

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageVolume.generated.h"

UCLASS()
class IRONKNIGHT_API ADamageVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Damage);
	class UBoxComponent* DamageVolume;
	
	class UBillboardComponent* Billboard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Volume")
	class USoundCue* DamageSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Volume")
	TSubclassOf<UDamageType> DamageTypeClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Volume");
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Volume");
	float StartDamageDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Volume");
	float DamageDelay;

	class AMain* Main;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Volume")
	bool bCameraShake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Volume")
	float CameraShake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Volume")
	FLinearColor CameraColorFade;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Volume")
	float CameraOpacityFade;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Volume")
	float CameraFadeTiming;


	FTimerHandle DamageTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ApplyDamage();

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
