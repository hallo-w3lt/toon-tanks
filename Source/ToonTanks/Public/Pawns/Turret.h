// Copyright 2023 @hallo_w3lt. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Pawns/BasePawn.h"
#include "Turret.generated.h"

/**
 * Turret Class
 */
UCLASS()
class TOONTANKS_API ATurret final : public ABasePawn
{
	GENERATED_BODY()

public:
	explicit ATurret();
	virtual ~ATurret() override = default;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;

private:
	UPROPERTY()
	class ATank* Tank = nullptr;

	UPROPERTY(EditDefaultsOnly, Category="Ranges", meta=(AllowPrivateAccess="true"))
	float FireRange = 300.f;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;

	void CheckFireCondition();
	bool InFireRange() const;
};
