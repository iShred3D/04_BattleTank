// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Possesssing: %s"), *(ControlledTank->GetName()));
	}

	auto ThePlayersTank = GetPlayerTank();
	if (!ThePlayersTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI can't find the player!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI has located the player's tank! %s"), *(ThePlayersTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim at the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire if ready
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(GetPawn());
}