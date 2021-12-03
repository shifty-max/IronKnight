// Copyright Maksym (Maxim) Khytra. 


#include "MainAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Main.h"

//Getting skeletal mesh 
void UMainAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
			Main = Cast<AMain>(Pawn);
	}
}

//Function will update our animation every frame in derived animation blueprint class
void UMainAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
		Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);

		//Magnitude of vector will be current character's movment speed
		MovementSpeed = LateralSpeed.Size();

		//Checking if a player is in the air
		bIsInTheAir = Pawn->GetMovementComponent()->IsFalling();

		if(Main == nullptr)
			Main = Cast<AMain>(Pawn);
	}
}
