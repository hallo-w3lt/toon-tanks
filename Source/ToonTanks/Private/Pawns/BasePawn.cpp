// Copyright 2023 @hallo_w3lt. All Rights Reserved. 


#include "Pawns/BasePawn.h"

#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"
#include "Actors/Projectile.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	RootComponent = CapsuleComponent;

	TankBaseComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBase"));
	TankBaseComponent->SetupAttachment(RootComponent);

	TankTurretComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankTurret"));
	TankTurretComponent->SetupAttachment(TankBaseComponent);

	ProjectileComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectilePoint"));
	ProjectileComponent->SetupAttachment(TankTurretComponent);
}

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
}

void ABasePawn::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasePawn::HandleDestruction()
{
	if (DeathParticle != nullptr)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticle, GetActorLocation(), GetActorRotation());
	}

	if (DeathSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation(), GetActorRotation());
	}	

	if (DeathCameraShakeClass != nullptr)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);
	}
}

void ABasePawn::RotateTurret(const FVector LookAtTarget) const
{
	const FVector ToTarget = LookAtTarget - TankTurretComponent->GetComponentLocation();
	const FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

	TankTurretComponent->SetWorldRotation(FMath::RInterpConstantTo(TankTurretComponent->GetComponentRotation(),
		LookAtRotation,
		GetWorld()->GetDeltaSeconds(),
		350.f));
}

void ABasePawn::Fire()
{
	if (nullptr == GetWorld()) { return; }
	if (nullptr == ProjectileClass) { return; }

	FVector ProjectileLocation = ProjectileComponent->GetComponentLocation();
	FRotator ProjectileRotation = ProjectileComponent->GetComponentRotation();

	// DrawDebugSphere(GetWorld(),
	// 	ProjectileLocation,
	// 	25.f,
	// 	10.f,
	// 	FColor::Yellow,
	// 	false,
	// 	3.f
	// );

	if (AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileLocation, ProjectileRotation); Projectile != nullptr)
	{
		Projectile->SetOwner(this);
	}
}
