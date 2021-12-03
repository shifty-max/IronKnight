// Copyright Maksym (Maxim) Khytra.
// Camera shake class

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShake.h"
#include "MainCameraShake.generated.h"

/**
 * 
 */
UCLASS()
class IRONKNIGHT_API UMainCameraShake : public UMatineeCameraShake
{
	GENERATED_BODY()

public:
	UMainCameraShake();
};
