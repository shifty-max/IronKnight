// Copyright Maksym (Maxim) Khytra. 


#include "EnemyAnimInstance.h"
#include "Enemy.h"

//Getting skeletal mesh 
void UEnemyAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
			Enemy = Cast<AEnemy>(Pawn);
	}
}

//Function will update our animation every frame in derived animation blueprint class
void UEnemyAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			Enemy = Cast<AEnemy>(Pawn);
		}
	}
	if (Pawn)
	{
		//Magnitude of vector will be current character's movment speed
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();
	}
}