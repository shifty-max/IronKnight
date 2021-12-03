// Copyright Maksym (Maxim) Khytra.
// Classic moving floating platform class with adjutable speed, stop delay and ending point

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class IRONKNIGHT_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Platform)
	class UStaticMeshComponent* Mesh;

	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Platform | Audio")
	class UAudioComponent* PlatformAudioComponent;
	
	UPROPERTY(EditAnywhere)
	FVector StartPoint;

	//This variable wil be an editable widget for easy interaction in the editor
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	FVector EndPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Platform)
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Platform)
	float InterpTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Platform)
	float SoundRadius;


	UPROPERTY(BlueprintReadOnly, Category = Platform)
	float CurrentSpeed;

	FTimerHandle InterpTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Platform)
	bool bInterping;

	float DeltaCount = 0.f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Switches bInterping to stop or move a platform
	FORCEINLINE void ToggleInterping() { bInterping = !bInterping; };

};
