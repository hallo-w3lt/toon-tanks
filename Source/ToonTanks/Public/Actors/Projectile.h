// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	AProjectile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "components", meta = (AllowPrivateAccess = "true"))
		class UParticleSystemComponent* ParticleTrail = nullptr;

	UPROPERTY(EditAnyWhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			FVector NormalImpulse,
			const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "Damage", meta = (AllowPrivateAccess = "true"))
		float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
		UParticleSystem* HitParticles = nullptr;

	UPROPERTY(EditAnywhere, Category = "Sound")
		class USoundBase* LaunchSound = nullptr;

	UPROPERTY(EditAnywhere, Category = "Sound")
		class USoundBase* HitSound = nullptr;

	UPROPERTY(EditAnywhere, Category = "Camera Shake")
		TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};
