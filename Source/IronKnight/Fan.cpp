// Copyright Maksym (Maxim) Khytra. 


#include "Fan.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Main.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"
#include "Enemy.h"
#include "TimerManager.h"

AFan::AFan()
{

	CameraShake = 1.0f;
	CameraOpacityFade = 0.2;
	CameraColorFade = { 1.f, 0.5f, 0.5f };
	CameraFadeTiming = 0.3f;

	Damage = 7.0f;

	BladeCount = 4;

	bRotate = false;
	
	//Create  meshes TArray
	for (int i = 0; i < BladeCount; i++)
	{
		TmpMesh = CreateDefaultSubobject<UStaticMeshComponent>(*FString("BladeMesh" + FString::FromInt(i)));
		FanBladesMesh.Emplace(TmpMesh);
		FanBladesMesh[i]->SetupAttachment(GetRootComponent());
	}

	TmpMesh = nullptr;
	delete TmpMesh;

	//Create blade collsions TArray
	for (int i = 0; i< BladeCount; i++)
	{
		TmpCollision = CreateDefaultSubobject<UBoxComponent>(*FString("BladeCollision" + FString::FromInt(i)));
		FanBladesCollisions.Emplace(TmpCollision);
		FanBladesCollisions[i]->SetupAttachment(FanBladesMesh[i]);
	}

	TmpCollision = nullptr;
	//delete TmpCollision;
}

void AFan::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < BladeCount; i++)
	{
		FanBladesCollisions[i]->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
	}
}

//Fan rotation, we can change RotationRate in Blueprints
void AFan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator Rotation = GetActorRotation();
	Rotation.Roll += DeltaTime * RotationRate;
	SetActorRotation(Rotation);
}

void AFan::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);
		if (Main || Enemy)
		{
			if (OverlapParticles)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticles, GetActorLocation(), FRotator(0.0f), true);
			}
			if (OverlapSound)
			{
				UGameplayStatics::PlaySound2D(this, OverlapSound);
			}

			if (TmpCollision != nullptr)
			{
				//here enable collision of a previous blade which store in TmpCollision to avoid multioverlapping for one time
				TmpCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			}

			//use TmpCollision pntr to have acces to this blade when next blade will overlap 
			TmpCollision = Cast<UBoxComponent>(OverlappedComponent);

			UGameplayStatics::ApplyDamage(OtherActor, Damage, nullptr, this, DamageTypeClass);

			//here disable collision of a blade to avoid multioverlapping for one time
			OverlappedComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			Main->CameraShake(CameraShake, CameraOpacityFade, CameraFadeTiming, CameraColorFade);
		}
	}
}