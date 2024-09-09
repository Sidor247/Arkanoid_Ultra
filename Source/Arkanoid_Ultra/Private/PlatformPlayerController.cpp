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
        InputComponent->BindAction("CloseGame", EInputEvent::IE_Pressed, this, &APlatformPlayerController::Exit);
    }
    OnBeginPlayCustom();
}

void APlatformPlayerController::OnPossess(APawn* PawnToPossess)
{
    Super::OnPossess(PawnToPossess);
    platformPawn = Cast<APlatformPawn>(PawnToPossess);
    if (!IsEventBounded)
    {
        platformPawn->OnDeathEvent.AddDynamic(this, &APlatformPlayerController::OnPawnDeath);
        IsEventBounded = true;
    }
}

void APlatformPlayerController::OnBeginPlayCustom_Implementation()
{
}

void APlatformPlayerController::OnPawnDeathNativeEvent_Implementation()
{
}

void APlatformPlayerController::PlatformMoveCallback(float AxisValue)
{
    platformPawn->Move(AxisValue);
}

void APlatformPlayerController::PlatformBallReleaseCallback()
{
    platformPawn->ReleaseBall();
}

void APlatformPlayerController::Exit()
{
    UKismetSystemLibrary::QuitGame(GetWorld(), this, EQuitPreference::Quit, false);
}

void APlatformPlayerController::OnPawnDeath()
{
    OnPawnDeathNativeEvent();
}
