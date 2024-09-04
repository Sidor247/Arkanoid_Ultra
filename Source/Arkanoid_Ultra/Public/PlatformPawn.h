#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <EnhancedInputLibrary.h>
#include "PlatformPawn.generated.h"

UCLASS()
class ARKANOID_ULTRA_API APlatformPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category = "Editables") UStaticMeshComponent* StaticMeshComponent = nullptr;

	APlatformPawn();
};
