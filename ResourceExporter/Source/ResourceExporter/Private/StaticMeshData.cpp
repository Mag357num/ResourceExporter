#include "StaticMeshData.h"

FStaticMeshData::FStaticMeshData(TArray<FVertexStruct> Vertices, TArray<int32> Indices) : Indices(Indices), Vertices(Vertices)
{
	VsFormat =
		TEXT("INDEX,")
		TEXT("POSITION,")
		TEXT("NORMAL,")
		TEXT("TEXCOORD0,")
		TEXT("TEXCOORD1,")
		TEXT("TEXCOORD2");

	VerticesNum = Vertices.Num();
}