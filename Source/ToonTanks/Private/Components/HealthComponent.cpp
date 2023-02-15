// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"
#include "Behaviour/ToonTanksGameMode.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);

	ToonTanksGameMode = Cast<AToonTanksGameMode>(UGameplayStatics::GetGameMode(this));
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCause)
{
	if (nullptr == ToonTanksGameMode) { return; }
	if (nullptr == DamagedActor) { return; }
	if (Damage <= 0.f) { return; }

	Health -= Damage;

	if (0.f == Health)
	{
		ToonTanksGameMode->ActorDied(DamagedActor);
	}

	// UE_LOG(LogTemp, Warning, TEXT("On Damaged %f"), Health);
	//UE_LOG(LogTemp, Warning, TEXT("On Damaged"));	
	// if (nullptr == Instigator) { return; }
	// UE_LOG(LogTemp, Warning, TEXT("Instigator: %s"), *Instigator->GetName());
}
