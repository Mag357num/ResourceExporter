//Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StaticMeshExporterJson.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct RESOURCEEXPORTER_API FStaticMeshExporterJson
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "PluginTest")
	FString VsFormat;

	UPROPERTY(BlueprintReadOnly, Category = "PluginTest")
	TArray<int32> Indices;

	UPROPERTY(BlueprintReadOnly, Category = "PluginTest")
	TArray<FVector> Vertices;

public:
	FStaticMeshExporterJson() = default;

	FStaticMeshExporterJson(TArray<FVector> Vertices, TArray<int32> Indices) : VsFormat(FString("..")), Indices(Indices), Vertices(Vertices) {}

};
