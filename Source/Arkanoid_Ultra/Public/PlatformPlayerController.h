#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <EnhancedInputLibrary.h>
#include <PlatformPawn.h>
#include "PlatformPlayerController.generated.h"

UCLASS()
class ARKANOID_ULTRA_API APlatformPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APlatformPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* PawnToPossess) override;

private:
	APlatformPawn* platformPawn = nullptr;

	void PlatformMoveCallback(float AxisValue);
	void PlatformBallReleaseCallback();
	void Exit();
};