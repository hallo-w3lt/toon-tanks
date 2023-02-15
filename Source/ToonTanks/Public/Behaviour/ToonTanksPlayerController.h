// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ToonTanksPlayerController.generated.h"

/**
 * PlayerController Class
 */
UCLASS()
class TOONTANKS_API AToonTanksPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
		explicit AToonTanksPlayerController();
		virtual ~AToonTanksPlayerController() = default;

public:
	void SetPlayerEnabledState(bool bPlayerEnabled);
	
};
