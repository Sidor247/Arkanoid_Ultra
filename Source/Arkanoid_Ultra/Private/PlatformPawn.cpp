#include "PlatformPawn.h"
#include <EnhancedInputComponent.h>

APlatformPawn::APlatformPawn()
{
 //	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	RootComponent = StaticMeshComponent;
    AutoReceiveInput = EAutoReceiveInput::Player0;
    AutoPossessPlayer = EAutoReceiveInput::Player0;
}


