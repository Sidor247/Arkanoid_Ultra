#include "Ball.h"
#include <Kismet/KismetMathLibrary.h>

ABall::ABall() : AActor()
{
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	direction = FVector2D(UKismetMathLibrary::RandomUnitVector());
	outSweepHitResult = FHitResult();
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector direction3D = FVector(direction, 0.0).GetSafeNormal(0.0001);
	FVector deltaLocation = DeltaTime * Speed * direction3D;
	AddActorWorldOffset(deltaLocation, true, &outSweepHitResult);
	if (outSweepHitResult.bBlockingHit) {
		FVector reflected = UKismetMathLibrary::GetReflectionVector(direction3D, outSweepHitResult.Normal);
		direction = FVector2D(reflected);
	}
}