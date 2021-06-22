// Fill out your copyright notice in the Description page of Project Settings.


#include "OutputSupportTypes.h"
#include "Serialization/Archive.h"

namespace RE
{
	FArchive& operator<<(FArchive& Ar, FJoint_RE& Value)
	{
		Ar << Value.Name;
		Ar << Value.ParentIndex;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FStaticVertex_RE& Value)
	{
		Ar << Value.Position;
		Ar << Value.TangentZ;
		Ar << Value.UV0;
		Ar << Value.Color;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FSkinnedWeightVertex_RE& Value)
	{
		Ar << Value.InfluJointIndice;
		Ar << Value.InfluJointWeights;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FStaticMesh_Lod_RE& Value)
	{
		Ar << Value.VertStride;
		Ar << Value.Vertice;
		Ar << Value.Indices;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FSkeletalMesh_Lod_RE& Value)
	{
		Ar << Value.VertStride;
		Ar << Value.Vertice;
		Ar << Value.SkinnedWeightVertice;
		Ar << Value.Indices;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FCamera_RE& Value)
	{
		Ar << Value.Position;
		Ar << Value.Dir;
		Ar << Value.Rotator;
		Ar << Value.Fov;
		Ar << Value.Aspect;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FTransfrom_RE& Value)
	{
		Ar << Value.Scale;
		Ar << Value.Quat;
		Ar << Value.Translation;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FCameraComponent_RE& Value)
	{
		Ar << Value.Bounding;
		Ar << Value.Transform;
		Ar << Value.ProjectionMode;
		Ar << Value.FieldOfView;
		Ar << Value.AspectRatio;
		Ar << Value.OrthoWidth;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FDirectionalLightComponent_RE& Value)
	{
		Ar << Value.Bounding;
		Ar << Value.Transform;
		Ar << Value.LightColor;
		Ar << Value.Intensity;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FPointLightComponent_RE& Value)
	{
		Ar << Value.Bounding;
		Ar << Value.Transform;
		Ar << Value.LightColor;
		Ar << Value.Intensity;
		Ar << Value.AttenuationRadius;
		Ar << Value.SourceRadius;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FStiaticMeshComponent_RE& Value)
	{
		Ar << Value.Bounding;
		Ar << Value.Transform;
		Ar << Value.StaticMesh;
		Ar << Value.Materials;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FBoxSphereBounds_RE& Value)
	{
		Ar << Value.Origin;
		Ar << Value.BoxExtent;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, AActor_RE& Value)
	{
		Ar << Value.Name;
		Ar << Value.Type;
		Ar << Value.CamComponents;
		Ar << Value.DLightComponents;
		Ar << Value.PLightComponents;
		Ar << Value.SMComponents;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FScene_RE& Value)
	{
		Ar << Value.Actors;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FSkeleton_RE& Value)
	{
		Ar << Value.Joints;
		Ar << Value.BindPose;
		Ar << Value.NameToIndexMap;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FTrack_RE& Value)
	{
		Ar << Value.Scales;
		Ar << Value.Quaternions;
		Ar << Value.Translations;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FSequence_RE& Value)
	{
		Ar << Value.SequenceLength;
		Ar << Value.NumFrames;
		Ar << Value.JointTracks;
		Ar << Value.TrackToJointIndexMapTable;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FMaterialInterface_RE& Value)
	{
		Ar << Value.IsMaterialInstance;
		Ar << Value.BaseMaterialName;
		Ar << Value.ScalarParams;
		Ar << Value.VectorParams;
		Ar << Value.TextureParams;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FMaterialInfo_RE& Value)
	{
		Ar << Value.MaterialName;
		return Ar;
	}

}
