// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "ExportStaticMeshToJsonBP.generated.h"

/**
 * 
 */
UCLASS()
class RESOURCEEXPORTER_API UExportStaticMeshToJsonBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "PluginTest")
	static void ExportStaticMesh(const UStaticMeshComponent* StaticMeshComponent, FString OutputPath = TEXT(""), const FString Filename = TEXT("SingleStaticMesh_"));

	UFUNCTION(BlueprintCallable, Category = "PluginTest")
	static TArray<FVector> GetVerticesData(const UStaticMeshComponent* StaticMeshComponent);

	UFUNCTION(BlueprintCallable, Category = "PluginTest")
	static TArray<int32> GetIndicesData(const UStaticMeshComponent* StaticMeshComponent);

	UFUNCTION(BlueprintCallable, Category = "PluginTest")
	static void ExportSMDataByJsonObj(const TArray<FVector>& Vertices, const TArray<int32>& Indices, FString OutputPath = TEXT(""), const FString Filename = TEXT("SingleStaticMesh_"));

	UFUNCTION(BlueprintCallable, Category = "PluginTest")
	static void ExportSMDataByJsonWriter(const TArray<FVector>& Vertices, const TArray<int32>& Indices, FString OutputPath = TEXT(""), const FString Filename = TEXT("SingleStaticMesh_"));

	UFUNCTION(BlueprintCallable, Category = "PluginTest")
	static void ExportSMDataByJsonConverter(const TArray<FVector>& Vertices, const TArray<int32>& Indices, FString OutputPath = TEXT(""), const FString Filename = TEXT("SingleStaticMesh_"));
};
