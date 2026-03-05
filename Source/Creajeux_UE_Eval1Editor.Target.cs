// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Creajeux_UE_Eval1EditorTarget : TargetRules
{
	public Creajeux_UE_Eval1EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Creajeux_UE_Eval1" } );
	}
}
