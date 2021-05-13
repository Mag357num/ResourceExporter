// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RenderDataExporterBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UENUM(BlueprintType)
enum class EVertexFormat : uint8 {
    POSITION = 0,
    NORMAL = 1,
    TEXCOORD0 = 2,
    TEXCOORD1 = 3,
    TANGENT = 4,
    COLOR = 5,
    MAX = 6,
};

USTRUCT()
struct FStaticMeshLODData
{
	GENERATED_BODY()

    UPROPERTY()
    uint32 NumVertices;
        
    UPROPERTY()
    uint32 NumTriangles;

    UPROPERTY()
    uint32 NumIndices;

    UPROPERTY()
    TArray<EVertexFormat> Format;

    UPROPERTY()
    TArray<float> Vertices;
    
    UPROPERTY()
    TArray<uint32> Indices;

    uint32 FormatBits;
};

FArchive& operator<<(FArchive& Ar, FStaticMeshLODData& Data);


USTRUCT()
struct FStaticMeshExportData
{
    GENERATED_BODY()

    UPROPERTY()
    FString Name;

    UPROPERTY()
    FString ExportPath;

    UPROPERTY()
    uint32 NumLOD;

    UPROPERTY()
    TArray<FStaticMeshLODData> LODs;
};

FArchive& operator<<(FArchive& Ar, FStaticMeshExportData& Data);

USTRUCT()
struct FCameraData
{
    GENERATED_BODY()

    UPROPERTY()
    FVector Location;

    UPROPERTY()
    FRotator Rotator;

    UPROPERTY()
    FQuat Rotation;

    UPROPERTY()
    FVector Direction;

    UPROPERTY()
    FVector Target;

    UPROPERTY()
    float FOV; 
        
    UPROPERTY()
    float Aspect;
};

FArchive& operator<<(FArchive& Ar, FCameraData& Data);

USTRUCT()
struct FTextureBinData
{
    GENERATED_BODY()

    UPROPERTY()
    uint32 Width;

    UPROPERTY()
    uint32 Height;

    UPROPERTY()
    TArray<uint8> Data;
};

FArchive& operator<<(FArchive& Ar, FTextureBinData& Data);

USTRUCT()
struct FMaterialInstanceData
{
    GENERATED_BODY()

    
};

USTRUCT()
struct FMeshMaterialData
{
    GENERATED_BODY()

    UPROPERTY()
    FString ShadingModel;

    UPROPERTY()
    FString VertexShaderPath;

    UPROPERTY()
    FString PixelShaderPath;

    UPROPERTY()
    TArray<FString> TexturePath;

};

FArchive& operator<<(FArchive& Ar, FMeshMaterialData& Data);

USTRUCT()
struct FStaticMeshSceneData
{
    GENERATED_BODY()

    UPROPERTY()
    FVector Location;

    UPROPERTY()
    FRotator Rotator;

    UPROPERTY()
    FVector Scale;

    UPROPERTY()
    FString AssetPath;

    UPROPERTY()
    FMeshMaterialData Material;
};

FArchive& operator<<(FArchive& Ar, FStaticMeshSceneData& Data);

USTRUCT()
struct FDirectionalLightData 
{
    GENERATED_BODY()

    UPROPERTY()
    FVector Color = {1,1,1};

    UPROPERTY()
    float Intensity = 1.0f;

    UPROPERTY()
    FVector Direction = { 0,0,-1 };
};
FArchive& operator<<(FArchive& Ar, FDirectionalLightData& Data);


USTRUCT()
struct FSceneRenderData
{
    GENERATED_BODY()

    UPROPERTY()
    TArray<FCameraData> Cameras;

    UPROPERTY()
    TArray<FStaticMeshSceneData> Meshes;

    UPROPERTY()
    FDirectionalLightData DirectionalLight;
};

FArchive& operator<<(FArchive& Ar, FSceneRenderData& Data);

USTRUCT(BlueprintType)
struct FExportStaticMeshOptions 
{
	GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    bool bPosition = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bNormal = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTexcoord0 = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bTexcoord1 = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bTangent = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bVertexColor = false;

};

UCLASS()
class URenderDataExporterBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "RenderDataExporter")
	static bool ExportMeshToJson(UStaticMesh* Mesh,const FExportStaticMeshOptions& Options, const FString& Path);

    UFUNCTION(BlueprintCallable, Category = "RenderDataExporter")
    static bool ExportCamerasToJson(const TArray<class UCameraComponent*>& Cameras,const FString& Path);

    UFUNCTION(BlueprintCallable, Category = "RenderDataExporter", meta=(WorldContext=WorldContextObject))
    static bool ExportMapToBinaries(UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "RenderDataExporter", meta = (WorldContext = WorldContextObject))
    static bool ExportMapToJson(UObject* WorldContextObject);
};
