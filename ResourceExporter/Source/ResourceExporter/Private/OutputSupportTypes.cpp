// Fill out your copyright notice in the Description page of Project Settings.


#include "OutputSupportTypes.h"
#include "Serialization/Archive.h"

namespace RE
{
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

	FArchive& operator<<(FArchive& Ar, FMeshTransfrom& Value)
	{
		Ar << Value.Translation;
		Ar << Value.Quat;
		Ar << Value.Scale;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FStaticMeshComponent_RE& Value)
	{
		Ar << Value.StaticMesh;
		Ar << Value.MeshTrans;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FScene_RE& Value)
	{
		Ar << Value.MeshActors;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FSkeleton_RE& Value)
	{
		Ar << Value.Joints;
		Ar << Value.BindPose;
		return Ar;
	}

	FArchive& operator<<(FArchive& Ar, FJoint_RE& Value)
	{
		Ar << Value.Name;
		Ar << Value.ParentIndex;
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
}
