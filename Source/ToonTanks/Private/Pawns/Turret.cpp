// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Turret.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/Tank.h"
#include "TimerManager.h"

ATurret::ATurret()
{
	// ...
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATurret::CheckFireCondition, FireRate, true);
}

void ATurret::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (nullptr == Tank) { return; }

	if (InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATurret::CheckFireCondition()
{
	if (InFireRange())
	{
		Fire();
	}
}

bool ATurret::InFireRange() const
{
	if (nullptr == Tank) { return false; }
	return FVector::Dist(GetActorLocation(), Tank->GetActorLocation()) <= FireRange && Tank->IsAlive();
}
