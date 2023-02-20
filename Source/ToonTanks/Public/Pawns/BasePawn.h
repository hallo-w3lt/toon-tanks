// Copyright 2023 @hallo_w3lt. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS(Abstract)
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	explicit ABasePawn();

	virtual ~ABasePawn() override = default;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction();

protected:
	void RotateTurret(FVector LookAtTarget) const;
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* CapsuleComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TankBaseComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TankTurretComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AProjectile> ProjectileClass = nullptr;


	UPROPERTY(EditAnywhere, Category = "FX", meta = (AllowPrivateAccess = "true"))
		class UParticleSystem* DeathParticle = nullptr;

	UPROPERTY(EditAnywhere, Category = "Sound")
		class USoundBase* DeathSound = nullptr;

	UPROPERTY(EditAnywhere, Category = "Camera Shake")
		TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
};
