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

	struct FStaticMesh_Lod_RE
	{
		int32 VertStride;
		TArray<FStaticVertex_RE> Vertice;
		TArray<int32> Indices;
	};

	struct FSkinnedWeightVertex_RE
	{
		TArray<uint16> InfluJointIndice;
		TArray<uint8> InfluJointWeights;
	};

	struct FSkeletalMesh_Lod_RE
	{
		uint32 VertStride;
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
		TMap<FString, int32> NameToIndexMap;
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

	struct FTransfrom_RE // TODO: change to use FTransform
	{
		FVector Translation;
		FQuat Quat;
		FVector Scale;
	};

	struct FMaterialInterface_RE
	{
		bool IsMaterialInstance;
		FString BaseMaterialName;
		TArray<float> ScalarParams;
		TArray<FVector4> VectorParams;
		TArray<FString> TextureParams;
	};

	struct FMaterialInfo_RE
	{
		FString MaterialName;
	};

	struct FBoxSphereBounds_RE
	{
		FBoxSphereBounds_RE() = default;
		FBoxSphereBounds_RE(FBoxSphereBounds Bounds) { Origin = Bounds.Origin; BoxExtent = Bounds.BoxExtent; }

		FVector Origin;
		FVector BoxExtent;
	};

	struct FDirectionalLightComponent_RE
	{
		FBoxSphereBounds_RE Bounding;
		FTransfrom_RE Transform;
		FLinearColor LightColor;
		float Intensity;
	};

	struct FPointLightComponent_RE
	{
		FTransfrom_RE Transform;
		FLinearColor LightColor;
		FBoxSphereBounds_RE Bounding;
		float Intensity;
		float AttenuationRadius;
		float SourceRadius;
	};

	struct FCameraComponent_RE
	{
		FBoxSphereBounds_RE Bounding;
		FTransfrom_RE Transform;
		uint32 ProjectionMode; // 0:persp, 1: ortho
		float FieldOfView;
		float AspectRatio;
	};

	struct FStiaticMeshComponent_RE
	{
		FBoxSphereBounds_RE Bounding;
		FStaticMesh_Lod_RE StaticMesh;
		FTransfrom_RE Transform;
		TArray<FMaterialInfo_RE> Materials;
	};

	enum class EActorType
	{
		STATICMESH_ACTOR = 0,
		CAMERA_ACTOR = 1,
		DIRECTIONALLIGHT_ACTOR = 2,
		POINTLIGHT_ACTOR = 3
	};

	struct AActor_RE
	{
		FString Name;
		EActorType Type;
		TArray<FStiaticMeshComponent_RE> SMComponents;
		TArray<FCameraComponent_RE> CamComponents;
		TArray<FDirectionalLightComponent_RE> DLightComponent;
		TArray<FPointLightComponent_RE> PLightComponents;
	};

	struct FScene_RE
	{
		TArray<AActor_RE> Actors;
	};

	FArchive& operator<<(FArchive& Ar, FBoxSphereBounds_RE& Value);

	FArchive& operator<<(FArchive& Ar, FJoint_RE& Value);

	FArchive& operator<<(FArchive& Ar, FStaticVertex_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSkinnedWeightVertex_RE& Value);

	FArchive& operator<<(FArchive& Ar, FStaticMesh_Lod_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSkeletalMesh_Lod_RE& Value);

	FArchive& operator<<(FArchive& Ar, FCamera_RE& Value);

	FArchive& operator<<(FArchive& Ar, FTransfrom_RE& Value);

	FArchive& operator<<(FArchive& Ar, FMaterialInterface_RE& Value);

	FArchive& operator<<(FArchive& Ar, FMaterialInfo_RE& Value);

	FArchive& operator<<(FArchive& Ar, FCameraComponent_RE& Value);

	FArchive& operator<<(FArchive& Ar, FDirectionalLightComponent_RE& Value);

	FArchive& operator<<(FArchive& Ar, FPointLightComponent_RE& Value);

	FArchive& operator<<(FArchive& Ar, FStiaticMeshComponent_RE& Value);

	FArchive& operator<<(FArchive& Ar, AActor_RE& Value);

	FArchive& operator<<(FArchive& Ar, FScene_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSkeleton_RE& Value);

	FArchive& operator<<(FArchive& Ar, FTrack_RE& Value);

	FArchive& operator<<(FArchive& Ar, FSequence_RE& Value);
}
