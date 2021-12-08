// Copyright Maksym (Maxim) Khytra. 


#include "EnemyTwoHandsMeele.h"
#include "Main.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GamePlayStatics.h"
#include "AIController.h"
#include "Sound/SoundCue.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"

AEnemyTwoHandsMeele::AEnemyTwoHandsMeele()
{
	CombatCollisionRight = CreateDefaultSubobject<UBoxComponent>(TEXT("CombatCollisionRight"));
	CombatCollisionRight->SetupAttachment(GetMesh(), FName("EnemySocket_r"));
}

void AEnemyTwoHandsMeele::BeginPlay()
{
	Super::BeginPlay();

	CombatCollisionRight->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::CombatOnOverlapBegin);

	CombatCollisionRight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CombatCollisionRight->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CombatCollisionRight->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CombatCollisionRight->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

void AEnemyTwoHandsMeele::CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			if (!Main->bBlock)
			{
				if (Main->HitParticles)
				{

					if (OverlappedComponent == CombatCollision)
					{
						const USkeletalMeshSocket* TipSocket = GetMesh()->GetSocketByName("TipSocket");
						if (TipSocket)
						{
							FVector SocketLocation = TipSocket->GetSocketLocation(GetMesh());
							UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Main->HitParticles, SocketLocation, FRotator(0.f), false);
						}
					}
					else
					{
						const USkeletalMeshSocket* TipSocket = GetMesh()->GetSocketByName("TipSocket_r");
						if (TipSocket)
						{
							FVector SocketLocation = TipSocket->GetSocketLocation(GetMesh());
							UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Main->HitParticles, SocketLocation, FRotator(0.f), false);
						}
					}
				}
				if (Main->HitSound)
				{
					UGameplayStatics::PlaySound2D(this, Main->HitSound);
				}
				if (DamageTypeClass)
				{
					UGameplayStatics::ApplyDamage(Main, Damage, AIController, this, DamageTypeClass);
					Main->CameraShake(CameraShake, CameraOpacityFade, CameraFadeTiming, CameraColorFade);
				}
			}
			
			//if attack is blocked nothing happens exept camera shake
			else
			{
				Main->CameraShake(CameraShake / 2, 0.f, 0.f, CameraColorFade);
			}
		}
	}
}


void AEnemyTwoHandsMeele::Die(AActor* DamageCauser)
{
	Super::Die(DamageCauser);

	CombatCollisionRight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEnemyTwoHandsMeele::ActivateCollisionRight()
{
	CombatCollisionRight->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AEnemyTwoHandsMeele::DeactivateCollisionRight()
{
	CombatCollisionRight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEnemyTwoHandsMeele::BlockCollisionRight()
{
	CombatCollisionRight->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
}