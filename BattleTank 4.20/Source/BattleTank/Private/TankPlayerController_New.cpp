// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_New.h"


void ATankPlayerController_New::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesssing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController_New::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

