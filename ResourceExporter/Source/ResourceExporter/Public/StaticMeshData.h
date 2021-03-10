//Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VertexStruct.h"
#include "StaticMeshData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct RESOURCEEXPORTER_API FStaticMeshData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "StaticMesh")
	int32 VerticesNum;

	UPROPERTY(BlueprintReadOnly, Category = "StaticMesh")
	TArray<int32> Indices;

	UPROPERTY(BlueprintReadOnly, Category = "StaticMesh")
	FString VsFormat;

	UPROPERTY(BlueprintReadOnly, Category = "StaticMesh")
	TArray<float> Vertices;

public:
	FStaticMeshData() = default;
	FStaticMeshData(TArray<float> Vertices, TArray<int32> Indices);
};
