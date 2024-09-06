#include "HUDWidgetBase.h"

void UHUDWidgetBase::SetLives(int Lives)
{
	LivesText = FString::Printf(TEXT("Lives: %d"), Lives);
}

void UHUDWidgetBase::SetScore(int Score)
{
	ScoreText = FString::Printf(TEXT("Score: %d"), Score);
}
