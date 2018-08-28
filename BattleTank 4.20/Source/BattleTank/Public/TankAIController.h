// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "DrawDebugHelpers.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:


private:
	void AimAtPlayer() const;
	//ATank* GetControlledTank() const;
	//ATank* GetPlayerTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	float AcceptanceRadius = 3000;
};
