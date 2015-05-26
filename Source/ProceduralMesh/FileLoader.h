// Fill out your copyright notice in the Description page of Project Settings.
// https://forums.unrealengine.com/showthread.php?2925-Read-data-from-File-Some-kind-of-dynamic-level

#pragma once

#include "Runtime/XmlParser/Public/XmlFile.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileLoader.generated.h"


/**
*
*/
UCLASS()



class PROCEDURALMESH_API UFileLoader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		/*UPROPERTY()
		TArray<bool> FloorTiles;*/

		/*	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tilemap")*/

		/*UPROPERTY()
		int32 TilemapSizeX;*/

		/*	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tilemap")*/
		/*UPROPERTY()
		int32 TilemapSizeY;*/

		//UFUNCTION(BlueprintCallable, Category = "Tilemap")
		//void ReadJsonFile(FString LevelName);

		

		UFUNCTION(BlueprintCallable, Category = "save")
		static bool FileSaveString(FString SaveTextB, FString FileNameB);

		UFUNCTION(BlueprintPure, Category = "save")
		static bool FileLoadString(FString FileNameA, FString& SaveTextA);


};
