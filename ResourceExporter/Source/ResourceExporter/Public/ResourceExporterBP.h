// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StaticMeshData.h"
#include "OutputSupportTypes.h"

#include "ResourceExporterBP.generated.h"

using namespace RE;

/**
 * 
 */
UCLASS()
class RESOURCEEXPORTER_API UResourceExporterBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportSkeletonBinary(const USkeleton* Skeleton, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SkeletonBinary_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportSkeletalMeshBinary(const USkeletalMesh* SkeletalMesh, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SkeletalMeshBinary_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport", meta = (WorldContext = WorldContextObject))
	static void ExportSceneBinary(const UObject* WorldContextObject, FString OutputPath = TEXT(""), const FString& Filename = TEXT("Scene_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportStaticMeshBinary(const UStaticMesh* StaticMesh, FString OutputPath = TEXT(""), const FString& Filename = TEXT("StaticMeshBinary_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportStaticMesh(const UStaticMesh* StaticMesh, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SingleStaticMesh_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportSMDataByJsonObj(const TArray<FVertexStruct>& Vertices, const TArray<int32>& Indices, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SingleStaticMesh_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportSMDataByJsonWriter(const TArray<FVertexStruct>& Vertices, const TArray<int32>& Indices, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SingleStaticMesh_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport", meta = (WorldContext = WorldContextObject))
	static void ExportCameraBinary(const UObject* WorldContextObject, const UCameraComponent* CameraComponent, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SingleCameraData_"));
	
	UFUNCTION(BlueprintCallable, Category = "ResExport", meta = (WorldContext = WorldContextObject))
	static void ExportCamera(const UObject* WorldContextObject, const UCameraComponent* CameraComponent, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SingleCameraData_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport", meta = (WorldContext = WorldContextObject))
	static void ExportAllCameras(const UObject* WorldContextObject, FString OutputPath = TEXT(""), const FString& Filename = TEXT("AllCameraData_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void WriteFile(const FString& FileString, FString OutputPath, const FString& Filename);

	// get staticmesh vertex
	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void GetStaticMeshVerticesData(const UStaticMesh* StaticMesh, TArray<float>& Output);

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void GetStaticMeshIndicesData(const UStaticMesh* StaticMesh, TArray<int32>& Output);

	template <typename TargetStruct>
	static void ExportStructByJsonConverter(const TargetStruct& Target, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SingleStaticMesh_"))
	{
		FString OutputString;
		FJsonObjectConverter::UStructToJsonObjectString(Target, OutputString);
		WriteFile(OutputString, OutputPath, Filename);
	}
private:
	static FStaticMesh GetDataFromUStaticMesh(const UStaticMesh* SM);
	static FSkeletalMesh GetDataFromUSkeletalMesh(const USkeletalMesh* SM);
	static FSkeleton GetDataFromUSkeleton(const USkeleton* Sk);

	// get skeletalmesh vertex
	static void GetSkeletalMeshVerticesData(const USkeletalMesh* SkeletalMesh, TArray<FStaticVertex>& Output);
	static void GetSkeletalMeshWeightVerticesData(const USkeletalMesh* SkeletalMesh, TArray<FSkinnedWeightVertex>& Output);
	static void GetSkeletalMeshIndicesData(const USkeletalMesh* SkeletalMesh, TArray<uint32>& Output);
};
