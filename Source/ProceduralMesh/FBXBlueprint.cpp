// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralMesh.h"
#include <FBXBlueprint.h>

#define SAMPLE_FILENAME "file.fbx"
//#include <fbxsdk.h>
//#include <fbxiosettings.h>

static bool gVerbose = true;


//typedef float(*_getCircleArea)(float radius); // Declare the DLL function.
//typedef float(*_getCircleArea)(float radius); // Declare the DLL function.

/*UFBXBLUEPRINT::UFBXBLUEPRINT(const class FObjectInitializer& PCIP) : Super(PCIP)
{

}*/
/*
//get mesh normals info
void GetNormals(FbxNode* pNode)
{
	if (!pNode)
		return;

	//get mesh
	FbxMesh* lMesh = pNode->GetMesh();
	if (lMesh)
	{
		//print mesh node name
		FBXSDK_printf("current mesh node: %s\n", pNode->GetName());
		
		fbxsdk::FbxVector4* verts = lMesh->GetControlPoints(0);

		int materialCount = lMesh->GetElementMaterialCount();

		if (materialCount > 1)
		{
			// We need to splitt this mesh into one mesh mer material.
		}

		//get the normal element
		FbxGeometryElementNormal* lNormalElement = lMesh->GetElementNormal();
		if (lNormalElement)
		{
			//mapping mode is by control points. The mesh should be smooth and soft.
			//we can get normals by retrieving each control point
			if (lNormalElement->GetMappingMode() == FbxGeometryElement::eByControlPoint)
			{
				//Let's get normals of each vertex, since the mapping mode of normal element is by control point
				for (int lVertexIndex = 0; lVertexIndex < lMesh->GetControlPointsCount(); lVertexIndex++)
				{
					int lNormalIndex = 0;
					//reference mode is direct, the normal index is same as vertex index.
					//get normals by the index of control vertex
					if (lNormalElement->GetReferenceMode() == FbxGeometryElement::eDirect)
						lNormalIndex = lVertexIndex;

					//reference mode is index-to-direct, get normals by the index-to-direct
					if (lNormalElement->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
						lNormalIndex = lNormalElement->GetIndexArray().GetAt(lVertexIndex);

					//Got normals of each vertex.
					FbxVector4 lNormal = lNormalElement->GetDirectArray().GetAt(lNormalIndex);
					if (gVerbose) FBXSDK_printf("normals for vertex[%d]: %f %f %f %f \n", lVertexIndex, lNormal[0], lNormal[1], lNormal[2], lNormal[3]);
					//add your custom code here, to output normals or get them into a list, such as KArrayTemplate<FbxVector4>
					//. . .
				}//end for lVertexIndex
			}//end eByControlPoint
			//mapping mode is by polygon-vertex.
			//we can get normals by retrieving polygon-vertex.
			else if (lNormalElement->GetMappingMode() == FbxGeometryElement::eByPolygonVertex)
			{
				int lIndexByPolygonVertex = 0;
				//Let's get normals of each polygon, since the mapping mode of normal element is by polygon-vertex.
				for (int lPolygonIndex = 0; lPolygonIndex < lMesh->GetPolygonCount(); lPolygonIndex++)
				{
					//get polygon size, you know how many vertices in current polygon.
					int lPolygonSize = lMesh->GetPolygonSize(lPolygonIndex);
					//retrieve each vertex of current polygon.
					for (int i = 0; i < lPolygonSize; i++)
					{
						int lNormalIndex = 0;
						//reference mode is direct, the normal index is same as lIndexByPolygonVertex.
						if (lNormalElement->GetReferenceMode() == FbxGeometryElement::eDirect)
							lNormalIndex = lIndexByPolygonVertex;

						//reference mode is index-to-direct, get normals by the index-to-direct
						if (lNormalElement->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
							lNormalIndex = lNormalElement->GetIndexArray().GetAt(lIndexByPolygonVertex);

						//Got normals of each polygon-vertex.
						FbxVector4 lNormal = lNormalElement->GetDirectArray().GetAt(lNormalIndex);
						if (gVerbose) FBXSDK_printf("normals for polygon[%d]vertex[%d]: %f %f %f %f \n",
							lPolygonIndex, i, lNormal[0], lNormal[1], lNormal[2], lNormal[3]);
						//add your custom code here, to output normals or get them into a list, such as KArrayTemplate<FbxVector4>
						//. . .

						lIndexByPolygonVertex++;
					}//end for i //lPolygonSize
				}//end for lPolygonIndex //PolygonCount

			}//end eByPolygonVertex
		}//end if lNormalElement

	}//end if lMesh

	//recursively traverse each node in the scene
	int i, lCount = pNode->GetChildCount();
	for (i = 0; i < lCount; i++)
	{
		GetNormals(pNode->GetChild(i));
	}
}
*/

float UFBXBLUEPRINT::getCircleAreaDLL() //(float radius)
{
	// Create the FBX SDK manager
	FbxManager* lSdkManager = FbxManager::Create();

	// Create an IOSettings object.
	FbxIOSettings * ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
	lSdkManager->SetIOSettings(ios);

	// ... Configure the FbxIOSettings object ...

	// Create an importer.
	FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

	// Declare the path and filename of the file containing the scene.
	// In this case, we are assuming the file is in the same directory as the executable.
	const char* lFilename = "file.fbx";

	// Initialize the importer.
	bool lImportStatus = lImporter->Initialize(lFilename, -1, lSdkManager->GetIOSettings());

	if (!lImportStatus) {
		printf("Call to FbxImporter::Initialize() failed.\n");
		printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
		exit(-1);
	}

	// Create a new scene so it can be populated by the imported file.
	FbxScene* lScene = FbxScene::Create(lSdkManager, "myScene");

	// Import the contents of the file into the scene.
	lImporter->Import(lScene);

	// The file has been imported; we can get rid of the importer.
	lImporter->Destroy();

	// File format version numbers to be populated.
	int lFileMajor, lFileMinor, lFileRevision;

	// Populate the FBX file format version numbers with the import file.
	lImporter->GetFileVersion(lFileMajor, lFileMinor, lFileRevision);


	int numofgeometrys = lScene->GetGeometryCount();

	for (int i = 0; i < numofgeometrys; i++)
	{
		fbxsdk::FbxGeometry* fbxgeo = lScene->GetGeometry(i);

	//	fbxsdk::FbxMesh* fbxmesh = fbxgeo->Get

		if (fbxgeo != 0)
		{
			int numofcontrolpoints =fbxgeo->GetControlPointsCount();
			FbxVector4* controlpoints = fbxgeo->GetControlPoints(0);
			// x[12] = controlpoints[12]->mData[0];

			//Fbxsdk::FbxVector4* pNormalArray;
			//fbxgeo->GetNormals(pNormalArray);
			//fbxgeo->GetNormalsIndices();

		//	fbxgeo->GetNormals();

		//	fbxgeo->get
		}
	}

	/*
	FbxClassId lShaderClassID = lSdkManager->FindFbxFileClass("Shader", "FlatShader");
	for(int i = 0; i < lNode->GetSrcObjectCount(lShaderClassID); i++) 
	{
		FbxObject* lObject = lNode->GetSrcObject(lShaderClassID, i);
	}
	*/
	return 1.00f;
}
	//*FPaths::GamePluginsDir(),
	/*FString filePath = FPaths::Combine(TEXT("D:\UnrealLee\UE4ProceduralMesh\Binaries\Win64\debug\"), TEXT("libfbxsdk.dll")); // Concatenate the plugins folder and the DLL file.
	if (FPaths::FileExists(filePath))
	{
		void *DLLHandle;
		DLLHandle = FPlatformProcess::GetDllHandle(*filePath); // Retrieve the DLL.
		if (DLLHandle != NULL)
		{*/
			// Create the FBX SDK manager
			//FbxManager* lSdkManager = FbxManager::Create();

		//	_getCircleArea DLLgetCircleArea = NULL; // Local DLL function pointer.
		//	FString procName = "getCircleArea"; // The exact name of the DLL function.
		/*	DLLgetCircleArea = (_getCircleArea)FPlatformProcess::GetDllExport(DLLHandle, *procName); // Export the DLL function.
			if (DLLgetCircleArea != NULL)
			{*/
			///	float out = DLLgetCircleArea(radius); // Call the DLL function, with arguments corresponding to the signature and return type of the function.
			//	return out; // return to UE
			//}
		//}
	//}
//	return 1.00f;
//}





