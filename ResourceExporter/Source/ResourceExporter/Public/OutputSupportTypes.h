// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace RE
{
	struct FStaticVertex_RE
	{
		FVector Position;
		FVector TangentZ;
		FVector2D UV0;
		FVector4 Color;
	}; // TODO:sizeof(FVertex) 的问题?

	struct FStaticMesh_RE
	{
		int32 VertStride;
		TArray<FStaticVertex_RE> Vertice;
		TArray<int32> Indices;
	};

	struct FSkinnedWeightVertex_RE
	{
		TArray<int16> InfluJointIndice;
		TArray<int8> InfluJointWeights;
	};

	struct FSkeletalMesh_RE
	{
		int32 VertStride;
		TArray<FStaticVertex_RE> Vertice;
		TArray<FSkinnedWeightVertex_RE> SkinnedWeightVertice;
		TArray<uint32> Indices;
	};

	struct FJoint_RE
	{
		FString Name;
		int32 ParentIndex;
	};

	struct FSkeleton_RE
	{
		TArray<FJoint_RE> Joints;
		TArray<FTransform> BindPose;
	};

	struct FTrack_RE
	{
		TArray<FVector> Scales;
		TArray<FQuat> Quaternions;
		TArray<FVector> Translations;
	};

	struct FSequence_RE
	{
		float SequenceLength;
		uint32 NumFrames;
		TArray<FTrack_RE> JointTracks;
		TArray<int32> TrackToJointIndexMapTable;
	};

	struct FCamera_RE
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
		FStaticMesh_RE MeshActor;
		FMeshTransfrom MeshTrans;
	};

	struct FScene_RE
	{
		TArray<FMeshActor> MeshActors;
	};

	FArchive& operator<<(FArchive& Ar, FJoint_RE& Value);

	FArchive& operator<<(FArchive& Ar, FStaticVertex_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSkinnedWeightVertex_RE& Value);

	FArchive& operator<<(FArchive& Ar, FStaticMesh_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSkeletalMesh_RE& Value);

	FArchive& operator<<(FArchive& Ar, FCamera_RE& Value);

	FArchive& operator<<(FArchive& Ar, FMeshTransfrom& Value);

	FArchive& operator<<(FArchive& Ar, FMeshActor& Value);

	FArchive& operator<<(FArchive& Ar, FScene_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSkeleton_RE& Value);

	FArchive& operator<<(FArchive& Ar, FTrack_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSequence_RE& Value);
}
