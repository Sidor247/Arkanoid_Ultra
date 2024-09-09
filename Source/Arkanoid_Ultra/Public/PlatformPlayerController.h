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
	UFUNCTION(BlueprintNativeEvent, Category = "Events") void OnBeginPlayCustom();
	UFUNCTION(BlueprintNativeEvent, Category = "Events") void OnPawnDeathNativeEvent();
	virtual void OnBeginPlayCustom_Implementation();
	virtual void OnPawnDeathNativeEvent_Implementation();
	UFUNCTION() void OnPawnDeath();

private:
	APlatformPawn* platformPawn = nullptr;
	bool IsEventBounded = false;

	void PlatformMoveCallback(float AxisValue);
	void PlatformBallReleaseCallback();
	void Exit();
};