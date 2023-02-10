// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectile.h"
#include "Components/StaticMeshComponent.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileComponent"));
	RootComponent = ProjectileComponent;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectile::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}
