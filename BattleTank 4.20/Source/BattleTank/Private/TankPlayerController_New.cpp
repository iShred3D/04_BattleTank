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

	FVector HitLocation;// OUT parameter
	if (GetSightRayHitLocation(HitLocation)) // side effect, is ray-trace
	{
		GetControlledTank()->AimAt(HitLocation);

		DrawDebugSphere
		(
			GetWorld(),
			HitLocation,
			24,
			16,
			FColor(255, 0, 0)
		);
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
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	return true;
}

// line trace along that direction, and see what is hit (up to a max range)
bool ATankPlayerController_New::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (
		GetWorld()->LineTraceSingleByChannel
		(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility
		)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
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

