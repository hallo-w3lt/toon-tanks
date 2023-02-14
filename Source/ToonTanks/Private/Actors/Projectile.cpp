// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileComponent"));
	RootComponent = ProjectileComponent;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->MaxSpeed = 1300.f;
	ProjectileMovementComponent->InitialSpeed = 1300.f;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileComponent->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse,
	const FHitResult& Hit)
{
	// auto Owner = GetOwner();
	if (nullptr == GetOwner()) { return; }

	// auto Instigator = Owner->GetInstigatorController();

	auto DamageTypeClass = UDamageType::StaticClass();

	if (OtherActor != nullptr && OtherActor != this && OtherActor != GetOwner())
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, GetOwner()->GetInstigatorController(), this, DamageTypeClass);
		Destroy();
	}

	// UE_LOG(LogTemp, Warning, TEXT("OtherActor %s"), *OtherActor->GetName());
}
