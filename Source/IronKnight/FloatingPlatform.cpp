// Copyright Maksym (Maxim) Khytra. 


#include "FloatingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Components/AudioComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AFloatingPlatform::AFloatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	PlatformAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PlatformAudioComponent"));
	PlatformAudioComponent->SetupAttachment(Mesh);
	PlatformAudioComponent->bAutoActivate = false;

	StartPoint = FVector(0.0f);
	EndPoint = FVector(0.0f);

	InterpSpeed = 4.0f;
	InterpTime = 1.f;
	SoundRadius = 0.f;

	bInterping = false;
}

// Called when the game starts or when spawned
void AFloatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	//PlatformAudioComponent->AttenuationOverrides.OmniRadius = SoundRadius;
	StartPoint = GetActorLocation();
	EndPoint += StartPoint;

	PlatformAudioComponent->Play();

	GetWorldTimerManager().SetTimer(InterpTimer, this, &AFloatingPlatform::ToggleInterping, InterpTime);
}

// Called every frame
void AFloatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Speed = Mesh->GetComponentVelocity();
	FVector LateralSpeed = FVector(Speed.X, Speed.Y, Speed.Z);
	//Magnitude of vector will be current character's movment speed
	float MovementSpeed = Mesh->GetComponentVelocity().Size();

	if (bInterping)
	{
		DeltaCount += DeltaTime;
		FVector CurrentLocation = GetActorLocation();
		FVector Interp = FMath::VInterpTo(CurrentLocation, EndPoint, DeltaCount, InterpSpeed/30);
		SetActorLocation(Interp);
		CurrentSpeed = (CurrentLocation - Interp).Size();
		PlatformAudioComponent->SetFloatParameter(FName("pitch"), CurrentSpeed /15.f);
		//If platform is at the end point we stop it for InterpTime and swap start and end points and moving starts again
		float Distance = (CurrentLocation - EndPoint).Size();
		if (Distance <= 5.0f)
		{
			ToggleInterping();
			GetWorldTimerManager().SetTimer(InterpTimer, this, &AFloatingPlatform::ToggleInterping, InterpTime);
			DeltaCount = 0.f;
			EndPoint = StartPoint;
			StartPoint = GetActorLocation();
		}
	}
 }