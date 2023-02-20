// Copyright 2023 @hallo_w3lt. All Rights Reserved. 


#include "Pawns/Tank.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/HealthComponent.h"
#include "DrawDebugHelpers.h"

ATank::ATank()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("UCameraComponet"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}


void ATank::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerController>(GetController());	
}

void ATank::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (nullptr == PlayerController) { return; }

	FHitResult HitResult;
	PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	// DrawDebugSphere(GetWorld(),
	//                 HitResult.ImpactPoint,
	//                 25.f,
	//                 10,
	//                 FColor::Red,
	//                 false,
	//                 -1.f);

	RotateTurret(HitResult.ImpactPoint);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	bAlive = false;
}

void ATank::Move(const float Val)
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Val * Speed * GetWorld()->GetDeltaSeconds();	

	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(const float Val)
{
	FRotator DeltaRotator = FRotator::ZeroRotator;
	DeltaRotator.Yaw = Val * TurnRate * GetWorld()->GetDeltaSeconds();

	AddActorLocalRotation(DeltaRotator, true);
}
