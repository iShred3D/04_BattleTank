// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel;

// Holds barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()


protected:
	// Called when the game starts

public:	
	// Called every frame
	UTankAimingComponent();
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelReference(class UTankBarrel* BarrelToSet);

private:
	class UTankBarrel * Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};
