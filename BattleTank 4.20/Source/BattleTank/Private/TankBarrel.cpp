// Fill out your copyright notice in the Description page of Project Settings.
#include "TankBarrel.h"
#include "Engine/World.h"
#include "UnrealMathUtility.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{

	auto SpeedClamped = FMath::Clamp<float>((RelativeSpeed), -1, +1);
	auto ElevationChange = SpeedClamped * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}