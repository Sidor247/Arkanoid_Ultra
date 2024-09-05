#include "PlatformPlayerController.h"
#include <EnhancedInputLibrary.h>
#include <Kismet/GameplayStatics.h>

APlatformPlayerController::APlatformPlayerController() {}

void APlatformPlayerController::BeginPlay()
{
    SetInputMode(FInputModeGameOnly());
    if (InputComponent)
    {
        InputComponent->BindAxis("PlatformMove", this, &APlatformPlayerController::PlatformMoveCallback);
    }
}

void APlatformPlayerController::OnPossess(APawn* PawnToPossess)
{
    Super::OnPossess(PawnToPossess);
    pawn = PawnToPossess;
}

void APlatformPlayerController::PlatformMoveCallback(float AxisValue)
{
    float deltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
    FVector deltaLocation(0.0, deltaSeconds * AxisValue * Speed, 0.0);
    pawn->AddActorWorldOffset(deltaLocation, true);
}