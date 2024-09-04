#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <vector>
#include <string>
#include "EditorStartupCommandsExecutor.generated.h"

UCLASS(Blueprintable)
class ARKANOID_ULTRA_API UEditorStartupCommandsExecutor : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable) void Start();

private:
	const std::vector<std::string> commands = {
		"-culture=en",
		"stat fps"
	};
};
