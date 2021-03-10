//Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VertexStruct.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct RESOURCEEXPORTER_API FVertexStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Vertex")
	int32 Index = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Vertex")
	FVector Position = FVector::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "Vertex")
	FVector Normal = FVector::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "Vertex")
	FVector2D TexCoord0 = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "Vertex")
	FVector2D TexCoord1 = FVector2D::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "Vertex")
	FVector2D TexCoord2 = FVector2D::ZeroVector;
};
