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
	static void ExportSequenceBinary(UAnimSequence* Sequence, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SequenceBinary_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportSkeletonBinary(const USkeleton* Skeleton, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SkeletonBinary_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportSkeletalMesh_Lod0_Binary(const USkeletalMesh* SkeletalMesh, FString OutputPath = TEXT(""), const FString& Filename = TEXT("SkeletalMeshBinary_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport", meta = (WorldContext = WorldContextObject))
	static void ExportSceneBinary(const UObject* WorldContextObject, FString OutputPath = TEXT(""), const FString& Filename = TEXT("Scene_"));

	UFUNCTION(BlueprintCallable, Category = "ResExport")
	static void ExportStaticMesh_Lod0_Binary(const UStaticMesh* StaticMesh, FString OutputPath = TEXT(""), const FString& Filename = TEXT("StaticMeshBinary_"));

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
	static FStaticMesh_Lod_RE GetDataFromUStaticMesh(const UStaticMesh* SM);
	static FSkeletalMesh_Lod_RE GetDataFromUSkeletalMesh(const USkeletalMesh* SM);
	static FSkeleton_RE GetDataFromUSkeleton(const USkeleton* Sk);
	static FSequence_RE GetDataFromUAnimSequence(UAnimSequence* Se);

	// get skeletalmesh data
	static void GetSkeletalMeshVerticesData(const USkeletalMesh* SkeletalMesh, TArray<FStaticVertex_RE>& Output);
	static void GetSkeletalMeshWeightVerticesData(const USkeletalMesh* SkeletalMesh, TArray<FSkinnedWeightVertex_RE>& Output);
	static void GetSkeletalMeshIndicesData(const USkeletalMesh* SkeletalMesh, TArray<uint32>& Output);

	// get skeleton data
	static void GetSkeletonJointsData(const USkeleton* Skeleton, TArray<FJoint_RE>& Output);
	static void GetSkeletonBindPoseData(const USkeleton* Skeleton, TArray<FTransform>& Output);

	// get sequence data
	static void GetSequenceLengthData(UAnimSequence* Sequence, float& Output);
	static void GetSequenceFrameNumData(const UAnimSequence* Sequence, uint32& Output);
	static void GetSequenceTracksData(const UAnimSequence* Sequence, TArray<FTrack_RE>& Output);
	static void GetSequenceTrackJointMapTableData(const UAnimSequence* Sequence, TArray<int32>& Output);
};
