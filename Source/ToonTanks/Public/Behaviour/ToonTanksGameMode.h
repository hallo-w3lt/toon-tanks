// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * GameMode Class
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	explicit AToonTanksGameMode();
	virtual ~AToonTanksGameMode() override = default;

protected:
	virtual void BeginPlay() override;

public:
	void ActorDied(AActor* DeadActor);

private:
	UPROPERTY()
	class ATank* Tank = nullptr;

	UPROPERTY()
	class AToonTanksPlayerController* PlayerController = nullptr;

	float StartDelay = 3.f;

	void HandleGameStart();
};
