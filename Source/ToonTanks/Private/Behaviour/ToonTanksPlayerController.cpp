// Copyright 2023 @hallo_w3lt. All Rights Reserved. 


#include "Behaviour/ToonTanksPlayerController.h"
#include "GameFramework/Pawn.h"

AToonTanksPlayerController::AToonTanksPlayerController()
{
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}

	bShowMouseCursor = bPlayerEnabled;
}
