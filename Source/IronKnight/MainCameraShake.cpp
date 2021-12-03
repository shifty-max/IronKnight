// Copyright Maksym (Maxim) Khytra.

#include "MainCameraShake.h"

UMainCameraShake::UMainCameraShake()
{
    OscillationDuration = 0.25f;
    OscillationBlendInTime = 0.05f;
    OscillationBlendOutTime = 0.05f;

    RotOscillation.Pitch.Amplitude = FMath::RandRange(4.0f, 8.0f);
    RotOscillation.Pitch.Frequency = FMath::RandRange(14.0f, 25.0f);

    RotOscillation.Yaw.Amplitude = FMath::RandRange(4.0f, 8.0f);
    RotOscillation.Yaw.Frequency = FMath::RandRange(14.0f, 25.0f);
}