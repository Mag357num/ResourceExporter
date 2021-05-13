// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace RE
{
	struct FJoint
	{
		FString Name;
		int32 ParentIndex;
	};

	struct FStaticVertex
	{
		FVector Position;
		FVector TangentZ;
		FVector2D UV0;
		FVector4 Color;
	}; // TODO:sizeof(FVertex) 的问题?

	struct FStaticMesh
	{
		int32 VertStride;
		TArray<FStaticVertex> Vertice;
		TArray<int32> Indices;
	};

	struct FSkinnedWeightVertex
	{
		TArray<int16> InfluJointIndice;
		TArray<int8> InfluJointWeights;
	};

	struct FSkeletalMesh
	{
		int32 VertStride;
		TArray<FStaticVertex> Vertice;
		TArray<FSkinnedWeightVertex> SkinnedWeightVertice;
		TArray<uint32> Indices;
	};

	struct FSkeleton_RE
	{
		TArray<FJoint> Joints;
		TArray<FTransform> BindPose;
	};

	struct FCamera
	{
		FVector Position;
		FVector Dir;
		FVector Rotator;
		float Fov;
		float Aspect;
	};

	struct FMeshTransfrom // TODO: change to use FTransform
	{
		FVector Translation;
		FQuat Quat;
		FVector Scale;
	};

	struct FMeshActor
	{
		FStaticMesh MeshActor;
		FMeshTransfrom MeshTrans;
	};

	struct FScene_RE
	{
		TArray<FMeshActor> MeshActors;
	};

	FArchive& operator<<(FArchive& Ar, FJoint& Value);

	FArchive& operator<<(FArchive& Ar, FStaticVertex& Value);

	FArchive& operator<<(FArchive& Ar, FSkinnedWeightVertex& Value);

	FArchive& operator<<(FArchive& Ar, FStaticMesh& Value);

	FArchive& operator<<(FArchive& Ar, FSkeletalMesh& Value);

	FArchive& operator<<(FArchive& Ar, FCamera& Value);

	FArchive& operator<<(FArchive& Ar, FMeshTransfrom& Value);

	FArchive& operator<<(FArchive& Ar, FMeshActor& Value);

	FArchive& operator<<(FArchive& Ar, FScene_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSkeleton_RE& Value);
}
