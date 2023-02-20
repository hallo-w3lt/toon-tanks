// Copyright 2023 @hallo_w3lt. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ToonTanksPlayerController.generated.h"

/**
 * PlayerController Class
 */
UCLASS()
class TOONTANKS_API AToonTanksPlayerController final : public APlayerController
{
	GENERATED_BODY()

public:
		explicit AToonTanksPlayerController();
		virtual ~AToonTanksPlayerController() = default;

public:
	void SetPlayerEnabledState(bool bPlayerEnabled);

};
