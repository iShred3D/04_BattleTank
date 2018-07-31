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


void ATankPlayerController_New::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}


ATank* ATankPlayerController_New::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController_New::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OUT parameter
	if (GetSightRayHitLocation(HitLocation)) // side effect, is ray-trace
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}

	// If it hits the landscape
		// Tell controlled tank to aim at this point
}

// Get world location of linetrace through crosshair, return true if hit landscape
bool ATankPlayerController_New::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXPosition, ViewportSizeY * CrosshairYPosition); // finds crosshair in pixel screenspace coords
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction = %s."), *(LookDirection.ToString()));
	}
	
	// line trace along that direction, and see what is hit (up to a max range)
	return true;
}

bool ATankPlayerController_New::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // to be discarded
	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}