// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Tank.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

ATank::ATank()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("UCameraComponet"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	// AddComponent(HealthComponent);
}


void ATank::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerController>(GetController());

	// DrawDebugSphere(GetWorld(),
	//                 GetActorLocation() + FVector(0.f, 0.f, 200.f),
	//                 100.f,
	//                 10,
	//                 FColor::Red,
	//                 true,
	//                 5.f);
}

void ATank::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (nullptr == PlayerController) { return; }

	FHitResult HitResult;
	PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	DrawDebugSphere(GetWorld(),
	                HitResult.ImpactPoint,
	                25.f,
	                10,
	                FColor::Red,
	                false,
	                -1.f);

	RotateTurret(HitResult.ImpactPoint);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

void ATank::Move(const float Val)
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Val * Speed * GetWorld()->GetDeltaSeconds();
	// DeltaLocation.X = Val * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(const float Val)
{
	FRotator DeltaRotator = FRotator::ZeroRotator;
	DeltaRotator.Yaw = Val * TurnRate * GetWorld()->GetDeltaSeconds();

	AddActorLocalRotation(DeltaRotator, true);
}
