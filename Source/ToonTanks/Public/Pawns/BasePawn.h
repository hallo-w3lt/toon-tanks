// Fill out your copyright notice in the Description page of Project Settings.

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

protected:
	void RotateTurret(FVector LookAtTarget) const;
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComponent2 = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="components", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* TankBaseComponent2 = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TankTurretComponent2 = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileComponent2 = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Class Types", meta=(AllowPrivateAccess= "true"))
	TSubclassOf<class AProjectile> ProjectileClass = nullptr;
};
