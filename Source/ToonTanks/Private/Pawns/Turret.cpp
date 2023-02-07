// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Turret.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/Tank.h"

ATurret::ATurret()
{
	// ...
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATurret::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (nullptr == Tank) { return; }

	if (const float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation()); Distance <= FireRange )
	{
		RotateTurret(Tank->GetActorLocation());
	}
}
