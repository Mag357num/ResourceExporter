#include "StaticMeshData.h"

FStaticMeshData::FStaticMeshData(TArray<float> Vertices, TArray<int32> Indices) : Indices(Indices), Vertices(Vertices)
{
	VsFormat =
		TEXT("POSITION,")
		TEXT("NORMAL,")
		TEXT("TEXCOORD0,")
		TEXT("TEXCOORD1");

	VerticesNum = Vertices.Num();
}