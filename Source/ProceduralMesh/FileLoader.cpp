// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralMesh.h"
#include "FileLoader.h"
#include "Json.h"


bool UFileLoader::FileSaveString(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}

bool UFileLoader::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	//FXmlFile file(L"D://test.xml");
	//auto pRoot = file.GetRootNode();

	//pRoot->

	//FXmlFile* testXml = new FXmlFile();
	//testXml->

	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}

/*
void UFileLoader::ReadJsonFile(FString LevelName)
{
if (LevelName.IsEmpty())
{
return;
}

// remove all tile information from previous parsing
FloorTiles.Empty();

// read level json file into json object
FString FullPath = FPaths::GameDir() + "ContentRaw/Tilemaps/" + LevelName + ".json";
FString JsonStr;
FFileHelper::LoadFileToString(JsonStr, *FullPath);
TSharedRef<TJsonReader<TCHAR>> JsonReader = FJsonStringReader::Create(JsonStr);
TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
bool serialized = FJsonSerializer::Deserialize(JsonReader, JsonObject);

if (!serialized)
{
return;
}

// read tile data from json
TArray<TSharedPtr<FJsonValue>> LayersArray = JsonObject->GetArrayField(TEXT("layers"));
TSharedPtr<FJsonObject> LayersObject = LayersArray[0]->AsObject();
TArray<TSharedPtr<FJsonValue>> TilesArray = LayersObject->GetArrayField(TEXT("data"));

// parse read tile array into floor tilemap
for (int i = 0; i < TilesArray.Num(); i++)
{
int32 TileVal = (int32)TilesArray[i]->AsNumber();
FloorTiles.Add(TileVal == 1);
}

// read tilemap size x and y from json
TilemapSizeX = (int32)LayersObject->GetNumberField(TEXT("width"));
TilemapSizeY = (int32)LayersObject->GetNumberField(TEXT("height"));
}
*/



