#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <EnhancedInputLibrary.h>
#include "PlatformPlayerController.generated.h"

UCLASS()
class ARKANOID_ULTRA_API APlatformPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APlatformPlayerController();

	UPROPERTY(EditInstanceOnly, Category = "Editables") double Speed = 500.0;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* PawnToPossess) override;

private:
	APawn* pawn = nullptr;

	void PlatformMoveCallback(float AxisValue);
};