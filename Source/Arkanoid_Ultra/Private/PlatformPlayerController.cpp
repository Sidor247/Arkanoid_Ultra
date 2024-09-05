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
        InputComponent->BindAction("BallRelease", EInputEvent::IE_Pressed, this, &APlatformPlayerController::PlatformBallReleaseCallback);
    }
}

void APlatformPlayerController::OnPossess(APawn* PawnToPossess)
{
    Super::OnPossess(PawnToPossess);
    platformPawn = Cast<APlatformPawn>(PawnToPossess);
}

void APlatformPlayerController::PlatformMoveCallback(float AxisValue)
{
    platformPawn->Move(AxisValue);
}

void APlatformPlayerController::PlatformBallReleaseCallback()
{
    platformPawn->ReleaseBall();
}
