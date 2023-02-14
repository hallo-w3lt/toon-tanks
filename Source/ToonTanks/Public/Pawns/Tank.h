// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/BasePawn.h"
#include "Tank.generated.h"

/**
 * Tank Class
 */
UCLASS()
class TOONTANKS_API ATank final : public ABasePawn
{
	GENERATED_BODY()

public:
	explicit ATank();
	virtual ~ATank() override = default;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category="Movements", meta = (AllowPrivateAccess = "true"))
	float Speed = 400.f;

	UPROPERTY(EditAnywhere, Category = "Movements", meta = (AllowPrivateAccess = "true"))
	float TurnRate = 45.f;

	UPROPERTY()
	APlayerController* PlayerController = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* SpringArmComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent = nullptr;

	// UPROPERTY(VisiblrAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	// class UHealthComponent* HealthComponent = nullptr;

	void Move(float Val);
	void Turn(float Val);
};
