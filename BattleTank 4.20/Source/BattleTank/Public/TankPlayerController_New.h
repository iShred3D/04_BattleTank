// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "TankPlayerController_New.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_New : public APlayerController
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
		
private:
	ATank * GetControlledTank() const;

	void AimTowardsCrosshair();

	// return OUT parameter,  true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXPosition = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYPosition = 0.3333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	
};
