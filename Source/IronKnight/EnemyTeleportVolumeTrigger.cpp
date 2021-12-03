// Copyright Maksym (Maxim) Khytra.
// Triger Volume class, teleports an enemy to location set with a widget


#include "EnemyTeleportVolumeTrigger.h"
#include "FXVolumeTrigger.h"
#include "Engine/World.h"
#include "Enemy.h"
#include "AIController.h"
#include "Components/BoxComponent.h"
#include "Main.h"

void AEnemyTeleportVolumeTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			if (Enemy)
			{
				UWorld* World = GetWorld();
				FActorSpawnParameters SpawnPararameters;

				if (World)
				{
					AEnemy* SpawningEnemy = World->SpawnActor<AEnemy>(Enemy, TrigerBox->GetComponentLocation() + FXPoint, FRotator(0.f), SpawnPararameters);
					if (SpawningEnemy)
					{
						SpawningEnemy->SpawnDefaultController();

						AAIController* AIContr = Cast<AAIController>(SpawningEnemy->GetController());
						if (AIContr)
						{
							SpawningEnemy->AIController = AIContr;
						}
					}
				}
			}
		}
	}
}

