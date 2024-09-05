#include "PlatformPawn.h"
#include <EnhancedInputComponent.h>
#include <Ball.h>
#include "Engine/World.h"
#include <Kismet/GameplayStatics.h>

void APlatformPawn::BeginPlay()
{
	Super::BeginPlay();
	spawnNewBall();
}

void APlatformPawn::Tick(float DeltaSeconsds)
{
	Super::Tick(DeltaSeconsds);
	if (ballToRelease) {
		FVector location = GetActorLocation();
		location.X += BallOffset;
		ballToRelease->SetActorLocation(location);
	}
}

APlatformPawn::APlatformPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	RootComponent = StaticMeshComponent;
	AutoReceiveInput = EAutoReceiveInput::Player0;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APlatformPawn::Move(float AxisValue)
{
	float deltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	FVector deltaLocation(0.0, deltaSeconds * AxisValue * Speed, 0.0);
	AddActorWorldOffset(deltaLocation, true);
}

void APlatformPawn::ReleaseBall()
{
	if (ballToRelease) {
		ballToRelease->Throw();
		ballToRelease = nullptr;
	}
}

void APlatformPawn::OnBallDestroy()
{
	if (RemainingBalls > 0)
		spawnNewBall();
}

void APlatformPawn::spawnNewBall()
{
	RemainingBalls--;
	FVector location = GetActorLocation();
	location.X += BallOffset;
	FTransform transform = FTransform::Identity;
	transform.SetLocation(location);
	ABall* spawnedBall = GetWorld()->SpawnActor<ABall>(BallClass, transform);
	ballToRelease = spawnedBall;
}
