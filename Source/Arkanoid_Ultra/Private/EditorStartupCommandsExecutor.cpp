#include "EditorStartupCommandsExecutor.h"
#include <Kismet/KismetSystemLibrary.h>

void UEditorStartupCommandsExecutor::Start()
{
	for (auto command : commands)
		UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), FString(command.c_str()));
}
