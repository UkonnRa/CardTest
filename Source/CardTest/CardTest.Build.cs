// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CardTest : ModuleRules
{
	public CardTest(ReadOnlyTargetRules target) : base(target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new[] { "Slate", "SlateCore" });
	}
}