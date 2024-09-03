// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ABall::ABall(): AActor()
{
	PrimaryActorTick.bCanEverTick = true;
	direction = FVector2D(UKismetMathLibrary::RandomUnitVector());
	outSweepHitResult = new FHitResult();
}

ABall::~ABall()
{
	delete outSweepHitResult;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector direction3D = FVector(direction, 0.0).GetSafeNormal(0.0001);
	FVector deltaLocation = DeltaTime * Speed * direction3D;
	AddActorWorldOffset(deltaLocation, true, outSweepHitResult);
	if (outSweepHitResult->bBlockingHit) {
		FVector reflected = UKismetMathLibrary::GetReflectionVector(direction3D, outSweepHitResult->Normal);
		direction = FVector2D(reflected);
	}
}

