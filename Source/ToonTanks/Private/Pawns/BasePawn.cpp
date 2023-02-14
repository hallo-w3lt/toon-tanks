// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/BasePawn.h"

#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"
#include "Actors/Projectile.h"

ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent2 = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	RootComponent = CapsuleComponent2;

	TankBaseComponent2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBase"));
	TankBaseComponent2->SetupAttachment(RootComponent);

	TankTurretComponent2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankTurret"));
	TankTurretComponent2->SetupAttachment(TankBaseComponent2);

	ProjectileComponent2 = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectilePoint"));
	ProjectileComponent2->SetupAttachment(TankTurretComponent2);
}

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
}

void ABasePawn::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasePawn::RotateTurret(const FVector LookAtTarget) const
{
	const FVector ToTarget = LookAtTarget - TankTurretComponent2->GetComponentLocation();
	const FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

	TankTurretComponent2->SetWorldRotation(FMath::RInterpConstantTo(TankTurretComponent2->GetComponentRotation(),
		LookAtRotation,
		GetWorld()->GetDeltaSeconds(),
		350.f));
}

void ABasePawn::Fire()
{
	if (nullptr == GetWorld()) { return; }
	if (nullptr == ProjectileClass) { return; }

	FVector ProjectileLocation = ProjectileComponent2->GetComponentLocation();
	FRotator ProjectileRotation = ProjectileComponent2->GetComponentRotation();

	DrawDebugSphere(GetWorld(),
		ProjectileLocation,
		25.f,
		10.f,
		FColor::Yellow,
		false,
		3.f
	);

	if (auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileLocation, ProjectileRotation); Projectile != nullptr) 
	{
		Projectile->SetOwner(this);
	}
}
