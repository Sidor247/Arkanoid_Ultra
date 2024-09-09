#include "Brick.h"
#include <Ball.h>
#include <Kismet/KismetSystemLibrary.h>

void ABrick::TriggerOnBrickDestroyEvent()
{
	OnBrickDestroyEvent.Broadcast();
}

ABrick::ABrick()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	OnActorHit.AddDynamic(this, &ABrick::OnHit);
}

void ABrick::OnHit(AActor*, AActor* OtherActor, FVector, const FHitResult&)
{
	if (Cast<ABall>(OtherActor))
		HandleBallHit();
}

void ABrick::HandleBallHit()
{
	if (--Lives <= 0) {
		TriggerOnBrickDestroyEvent();
		Destroy();
	}
}
