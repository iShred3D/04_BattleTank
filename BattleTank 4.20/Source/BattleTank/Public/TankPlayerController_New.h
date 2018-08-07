// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController_New.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_New : public APlayerController
{
	GENERATED_BODY()

public:

	
private:

	class ATank * GetControlledTank() const;

	virtual void Tick(float DeltaTime) override;

	void BeginPlay() override;

	void AimTowardsCrosshair();

	// return OUT parameter,  true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXPosition = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYPosition = 0.3333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	
};
