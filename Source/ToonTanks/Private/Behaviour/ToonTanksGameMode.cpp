// Fill out your copyright notice in the Description page of Project Settings.


#include "Behaviour/ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/Tank.h"
#include "Pawns/Turret.h"
#include "Behaviour/ToonTanksPlayerController.h"

AToonTanksGameMode::AToonTanksGameMode()
{
	// ...
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	PlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (nullptr == DeadActor) { return; }

	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();

		if (PlayerController != nullptr)
		{			
			PlayerController->SetPlayerEnabledState(false);
		}
	}

	else if (auto* Turret = Cast<ATurret>(DeadActor))
	{
		Turret->HandleDestruction();
	}
}
