// Copyright 2023 @hallo_w3lt. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOONTANKS_API UHealthComponent final : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		float MaxHealth = 100.f;

	float Health = 0.f;

	UFUNCTION()
		void DamageTaken(AActor* DamagedActor,
			float Damage,
			const UDamageType* DamageType,
			class AController* Instigator,
			AActor* DamageCause);

	UPROPERTY()
		class AToonTanksGameMode* ToonTanksGameMode = nullptr;
};
