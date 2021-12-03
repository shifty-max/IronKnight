// Copyright Maksym (Maxim) Khytra.
// Moving drawbridge class with adjutable speed, stop delay and ending point, broken true or false parameter, which activate VFX like explosion, etc...;
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Drawbridge.generated.h"

UCLASS()
class IRONKNIGHT_API ADrawbridge : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrawbridge();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Bridge)
	class UBoxComponent* TrigerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Bridge)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bridge)
	class UParticleSystemComponent* ExplosionParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bridge)
	class UParticleSystemComponent* BrokeParticles;

	UPROPERTY(EditAnywhere)
	FVector StartPoint;

	//This variable wil be an editable widget for easy interaction in the editor
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	FVector EndPoint;

	FTimerHandle InterpTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Bridge)
	bool bInterping;

	//If it is broken then = true
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Bridge)
	bool bBroken;

	//Sound for start moving mechanism
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bridge | Audio")
	class USoundCue* MechanismStart;

	//Sound when mechanism brokes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bridge | Audio")
	USoundCue* ExplosionSound;

	//Sound when mechanism workes, MUST BE looped!!!
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bridge | Audio")
	USoundCue* MechanismMovement;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Bridge | Audio")
	class UAudioComponent* BridgeAudioComponent;

	float DeltaCount;

	//Variable for moving speed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Bridge)
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Bridge)
	float InterpTime;

	//Distance when VFX activetes for bBroken
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Bridge)
	float BrokeDelayDistance;

	//Delay for movment start
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bridge)
	float MechanismStartDelay;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveBridge();
	void BridgeStuckMovement();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
