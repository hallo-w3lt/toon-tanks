// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/BasePawn.h"

#include "Components/CapsuleComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

void ABasePawn::RotateTurret(const FVector LookAtTarget)
{
	const FVector ToTarget = LookAtTarget - TankTurretComponent2->GetComponentLocation();
	const FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

	TankTurretComponent2->SetWorldRotation(FMath::RInterpConstantTo(TankTurretComponent2->GetComponentRotation(),
	                                                                LookAtRotation,
	                                                                GetWorld()->GetDeltaSeconds(),
	                                                                350.f));
}
