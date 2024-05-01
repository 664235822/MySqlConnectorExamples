// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MySqlConnector : ModuleRules
{
	public MySqlConnector(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(new string[] { "MySQLConnectorTools" });
		PublicDependencyModuleNames.AddRange(new string[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MySQLConnectorTools" });
	}
}