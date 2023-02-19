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

	HandleGameStart();
}

void AToonTanksGameMode::HandleGameStart()
{
	StartGame();
	Towers = GetTowerCount();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	PlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if (nullptr == PlayerController) { return; }

	PlayerController->SetPlayerEnabledState(false);

	FTimerHandle PlayerEnableTimerHandle;
	FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
		PlayerController,
		&AToonTanksPlayerController::SetPlayerEnabledState,
		true
	);

	GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableTimerDelegate, StartDelay, false);
}

int32 AToonTanksGameMode::GetTowerCount()
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), Actors);

	return Actors.Num();
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

		GameOver(false);
	}

	else if (ATurret* Turret = Cast<ATurret>(DeadActor))
	{
		Turret->HandleDestruction();
		--Towers;

		if (0 == Towers)
		{
			GameOver(true);
		}
	}
}
