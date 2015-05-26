
// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ProceduralMesh : ModuleRules
{
	public ProceduralMesh(TargetInfo Target)
	{

       // Type = ModuleType.External;

        string FBXSDKDir = /*UEBuildConfiguration.UEThirdPartySourceDirectory*/ "D:/Autodesk/FBX/" + "FBXSDK/2016.0/"; //"FBX/2014.2.1/"; D:\Autodesk\FBX\FBX SDK\2016.0
        PublicSystemIncludePaths.AddRange(
            new string[] {
					FBXSDKDir + "include",
					FBXSDKDir + "include/fbxsdk",
				}
            );


        if (Target.Platform == UnrealTargetPlatform.Win64)
        {  // D:\Autodesk\FBX\FBX SDK\2016.0\lib\vs2013\x64  was string FBxLibPath = FBXSDKDir  + "lib/vs2012/"; VS2013 libs are not readily available for FBX, so let's just use the 2012 ones whilst we can.
            string FBxLibPath = "D:/Autodesk/FBX/FBXSDK/2016.0/" + "lib/vs2013/"; 

           // FBxLibPath += "x64/release/";
           // FBxLibPath = "D:/Autodesk/FBX/FBXSDK/2016.0/lib/vs2013/x64/debug/";
            PublicLibraryPaths.Add(FBxLibPath);

            PublicAdditionalLibraries.Add("D:/Autodesk/FBX/FBXSDK/2016.0/lib/vs2013/x64/debug/libfbxsdk.lib");  // DEBUG LIB right know !!

            // We are using DLL versions of the FBX libraries
            Definitions.Add("FBXSDK_SHARED");
        }
    /*    else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            string LibDir = FBXSDKDir + "lib/mac/";
            PublicAdditionalLibraries.Add(LibDir + "libfbxsdk.dylib");
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            string LibDir = FBXSDKDir + "lib/linux/" + Target.Architecture;
            if (!Directory.Exists(LibDir))
            {
                string Err = string.Format("FBX SDK not found in {0}", LibDir);
                System.Console.WriteLine(Err);
                throw new BuildException(Err);
            }

            PublicAdditionalLibraries.Add(LibDir + "/libfbxsdk.a");
            // There is a bug in fbxarch.h where is doesn't do the check
            // * for clang under linux 
            Definitions.Add("FBXSDK_COMPILER_CLANG");
        }*/

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "XmlParser" });

		PrivateDependencyModuleNames.AddRange(new string[] { "RHI", "RenderCore", "ShaderCore" });

        //PrivateIncludePaths.Add("D:/Autodesk/FBX/FBX SDK/2016.0/include");
        //PrivateIncludePaths.Add("D:/Autodesk/FBX/FBX SDK/2016.0/include/fbxsdk/fileio");


		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}


