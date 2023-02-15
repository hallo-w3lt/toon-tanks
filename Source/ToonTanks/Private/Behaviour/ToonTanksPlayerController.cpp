// Fill out your copyright notice in the Description page of Project Settings.


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
