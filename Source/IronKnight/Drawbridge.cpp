// Copyright Maksym (Maxim) Khytra. 


#include "Drawbridge.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GamePlayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "Components/SceneComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "MainCameraShake.h"
#include "Main.h"

// Sets default values
ADrawbridge::ADrawbridge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TrigerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TrigerBox;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh-> SetupAttachment(GetRootComponent());

	ExplosionParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionParticles"));
	ExplosionParticles->SetupAttachment(GetRootComponent());
	ExplosionParticles->SetAutoActivate(false);

	BrokeParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BrokeParticles"));
	BrokeParticles->SetupAttachment(GetRootComponent());
	BrokeParticles->SetAutoActivate(false);

	BridgeAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("BridgeAudioComponent"));
	BridgeAudioComponent->SetupAttachment(GetRootComponent());
	BridgeAudioComponent->bAutoActivate = false;


	StartPoint = FVector(0.0f);
	EndPoint = FVector(0.0f);

	InterpSpeed = 0.05f;
	InterpTime = 0.1f;
	DeltaCount = 0.f;
	BrokeDelayDistance = 20.f;

	MechanismStartDelay = 1.f;

	bInterping = true;
}

// Called when the game starts or when spawned
void ADrawbridge::BeginPlay()
{
	Super::BeginPlay();

	StartPoint = Mesh->GetComponentLocation();
	EndPoint += StartPoint;

	if (BridgeAudioComponent->IsValidLowLevelFast())
	{
		BridgeAudioComponent->SetSound(MechanismMovement);
	}

	TrigerBox->OnComponentBeginOverlap.AddDynamic(this, &ADrawbridge::OnOverlapBegin);
	TrigerBox->OnComponentEndOverlap.AddDynamic(this, &ADrawbridge::OnOverlapEnd);
}

// Called every frame
void ADrawbridge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADrawbridge::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bInterping)
	{
		//Disable Collision, becasuse a bridge has to move to teh end
		OverlappedComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		//Play sound for start moving mechanism
		UGameplayStatics::PlaySound2D(this, MechanismStart);

		//Start timer for moving
		DeltaCount = GetWorld()->GetDeltaSeconds();
		GetWorldTimerManager().SetTimer(InterpTimer, this, &ADrawbridge::MoveBridge, DeltaCount, bInterping, MechanismStartDelay);
		BridgeAudioComponent->Play();
	}
}

void ADrawbridge::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ADrawbridge::MoveBridge()
{ 
	FVector CurrentLocation = Mesh->GetComponentLocation();
	float Distance = (CurrentLocation - EndPoint).Size();
	if (Distance <= 5.0f)
	{
		//Stops moving bridge when it almost get to the EndPoint
		bInterping = false;
		BridgeAudioComponent->Stop();
		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, StartPoint);
		TrigerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		GetWorldTimerManager().ClearTimer(InterpTimer);

		//if it is broken activating VFX like explosion ehen it gets to the EndPoint...
		if(bBroken)
		{
			if (ExplosionParticles)
			{
				ExplosionParticles->ActivateSystem();
				AMain* Main = Cast<AMain>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
				Main->CameraShake();
			}
			Mesh->SetSimulatePhysics(true);
		}
	}

	//if it is broken activating VFX like fire, smoke, etc... when bridge moves for BrokeDelayDistance
	if (bBroken && BrokeParticles && BrokeDelayDistance >= ((CurrentLocation - StartPoint).Size()) )
	{
		BrokeParticles->ActivateSystem();
	}

	//Moving a bridge
	DeltaCount += GetWorld()->GetDeltaSeconds();
	FVector Interp = FMath::VInterpTo(CurrentLocation, EndPoint, DeltaCount*InterpTime, InterpSpeed);
	Mesh->SetWorldLocation(Interp);
}