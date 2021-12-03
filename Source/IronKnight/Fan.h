// Copyright Maksym (Maxim) Khytra. 
// Class for spining fan which can bring harm to a player

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Fan.generated.h"


UCLASS()
class IRONKNIGHT_API AFan : public AItem
{
	GENERATED_BODY()

public:
	AFan();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	bool bCameraShake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraShake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	FLinearColor CameraColorFade;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraOpacityFade;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraFadeTiming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Damage)
	float Damage;

	//we can set fan blades count here and pass it as argument to TArray FanBladesMesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fan | Collision")
	int BladeCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Damage);
	float DamageTimeDelay;

	FTimerHandle DamageTimer;

	//Using that to fill TArray
	UStaticMeshComponent* TmpMesh;

	//Array for blade mashes
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fan | Mesh")
	TArray <UStaticMeshComponent*> FanBladesMesh;

	//Using that to fill TArray and enabling and disabling Overlapping of FanBlades during rotation
	class UBoxComponent* TmpCollision;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fan | Collision")
	TArray <UBoxComponent*> FanBladesCollisions;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	TSubclassOf<UDamageType> DamageTypeClass;

	virtual void Tick(float DeltaTime) override;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void BeginPlay() override;
};