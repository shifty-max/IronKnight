// Copyright Maksym (Maxim) Khytra.


#include "FXVolumeTrigger.h"
#include "Main.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystem.h"
#include "MainCameraShake.h"
#include "Kismet/GamePlayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/BillboardComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AFXVolumeTrigger::AFXVolumeTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TrigerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TrigerBox;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillboardComponent"));
	Billboard->SetupAttachment(GetRootComponent());

	FXPoint = FVector(0.0f);
	ActivationDelay = 0.1f;
	Frequency = 0.1f;
	bLooped = false;
	bCameraShake = false;
	bActivateOnce = true;
}

// Called when the game starts or when spawned
void AFXVolumeTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	TrigerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TrigerBox->OnComponentBeginOverlap.AddDynamic(this, &AFXVolumeTrigger::OnOverlapBegin);
}

// Called every frame
void AFXVolumeTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFXVolumeTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMain* Main = Cast<AMain>(OtherActor);
	if (Main)
	{
		GetWorldTimerManager().SetTimer(DelayTimer, this, &AFXVolumeTrigger::ActivateFX, Frequency, bLooped, ActivationDelay);
		if (bActivateOnce == true)
		{
			OverlappedComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}

void AFXVolumeTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AFXVolumeTrigger::ActivateFX()
{
	AMain* Main = Cast<AMain>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	UGameplayStatics::SpawnEmitterAtLocation(this, FXParticles, TrigerBox->GetComponentLocation()+FXPoint, GetActorRotation(), true);
	UGameplayStatics::PlaySoundAtLocation(this, SFXCue, GetActorLocation() + FXPoint);
	if (bCameraShake)
	{
		Main->CameraShake(1.f);
	}
}