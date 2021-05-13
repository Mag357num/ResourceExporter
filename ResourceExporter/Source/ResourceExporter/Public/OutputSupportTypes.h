// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class RESOURCEEXPORTER_API OutputSupportTypes
{
public:
	OutputSupportTypes();
	~OutputSupportTypes();
};

struct FVertexBinData
{
	FVector Position;
	FVector TangentZ;
	FVector2D UV0;
	FVector4 Color;
}; // sizeof(FVertex) 的问题?

struct FMeshBinData
{
	int32 VertStride;
	TArray<FVertexBinData> Vertice;
	TArray<int32> Indices;
};

struct FCameraBinData
{
	FVector Position;
	FVector Dir;
	FVector Rotator;
	float Fov;
	float Aspect;
};

struct FMeshTransfrom
{
	FVector Translation;
	FQuat Quat;
	FVector Scale;
};

struct FMeshActorBinData
{
	FMeshBinData MeshActor;
	FMeshTransfrom MeshTrans;
};

struct FSceneBinData
{
	TArray<FMeshActorBinData> MeshActors;
};
