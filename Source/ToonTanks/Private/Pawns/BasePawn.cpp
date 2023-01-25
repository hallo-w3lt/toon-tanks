// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/BasePawn.h"

#include "Components/CapsuleComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;

	TankBaseComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Base"));
	TankBaseComponent->SetupAttachment(RootComponent);

	TankTurretComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Turret"));
	TankTurretComponent->SetupAttachment(TankBaseComponent);

	ProjectileComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Point"));
	ProjectileComponent->SetupAttachment(TankTurretComponent);
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABasePawn::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
