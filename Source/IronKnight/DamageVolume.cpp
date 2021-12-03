// Copyright Maksym (Maxim) Khytra. 


#include "DamageVolume.h"
#include "Components/BoxComponent.h"
#include "Components/BillboardComponent.h"
#include "Sound/SoundCue.h"
#include "Main.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Math/Color.h"


// Sets default values
ADamageVolume::ADamageVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Damage = 25.f;

	//Delay when palyer stays inside volume
	StartDamageDelay = 1.f;

	//Delay for Overlap
	DamageDelay = 1.f;

	CameraShake = 1.0f;
	CameraOpacityFade = 0.2;
	CameraColorFade = { 1.f, 0.5f, 0.5f };
	CameraFadeTiming = 0.3f;


	DamageVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageVolume"));
	RootComponent = DamageVolume;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillboardComponent"));
	Billboard->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ADamageVolume::BeginPlay()
{
	Super::BeginPlay();

	DamageVolume->OnComponentBeginOverlap.AddDynamic(this, &ADamageVolume::OnOverlapBegin);
	DamageVolume->OnComponentEndOverlap.AddDynamic(this, &ADamageVolume::OnOverlapEnd);
	
}

// Called every frame
void ADamageVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ADamageVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		Main = Cast<AMain>(OtherActor);
		if (Main)
		{			
			if (Main->MovementStatus!= EMovementStatus::EMS_Dead)
			{
				GetWorldTimerManager().SetTimer(DamageTimer, this, &ADamageVolume::ApplyDamage, DamageDelay, true, StartDamageDelay);
			}
		}
	}
}

void ADamageVolume::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			if (Main->MovementStatus != EMovementStatus::EMS_Dead)
			{
				GetWorldTimerManager().ClearTimer(DamageTimer);
			}
		}
	}
}

void ADamageVolume::ApplyDamage()
{
	if (DamageSound)
	{
		UGameplayStatics::PlaySound2D(this, DamageSound);
	}
	if(bCameraShake)
	{
		AMain* TmpMain = Cast<AMain>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		TmpMain->CameraShake(CameraShake, CameraOpacityFade, CameraFadeTiming, CameraColorFade);
	}
	UGameplayStatics::ApplyDamage(Main, Damage, nullptr, this, DamageTypeClass);
}

