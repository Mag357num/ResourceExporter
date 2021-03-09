// Fill out your copyright notice in the Description page of Project Settings.


#include "ExportStaticMeshToJsonBP.h"
#include "StaticMeshExporterJson.h"
#include "JsonObjectConverter.h"

void UExportStaticMeshToJsonBP::ExportStaticMesh(const UStaticMeshComponent* StaticMeshComponent, FString Path, const FString Filename)
{
	TArray<FVector> Vertices = GetVerticesData(StaticMeshComponent);
	TArray<int32> Indices = GetIndicesData(StaticMeshComponent);
	ExportSMDataByJsonConverter(Vertices, Indices, Path, Filename);
}

TArray<FVector> UExportStaticMeshToJsonBP::GetVerticesData(const UStaticMeshComponent* StaticMeshComponent)
{
	TArray<FVector> vertices = TArray<FVector>();

	// Vertex Buffer
	if (!StaticMeshComponent) return vertices;
	if (!StaticMeshComponent->GetStaticMesh()) return vertices;
	if (!StaticMeshComponent->GetStaticMesh()->RenderData) return vertices;
	if (StaticMeshComponent->GetStaticMesh()->RenderData->LODResources.Num() > 0)
	{
		const FPositionVertexBuffer* VertexBuffer = &StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
		if (VertexBuffer)
		{
			const int32 VertexCount = VertexBuffer->GetNumVertices();
			for (int32 i = 0; i < VertexCount; i++)
			{
				const FVector VertexCoord = VertexBuffer->VertexPosition(i);
				vertices.Add(VertexCoord);
			}
		}
	}

	return vertices;
}

TArray<int32> UExportStaticMeshToJsonBP::GetIndicesData(const UStaticMeshComponent* StaticMeshComponent)
{
	TArray<int32> Indices = TArray<int32>();

	// Vertex Buffer
	if (!StaticMeshComponent) return Indices;
	if (!StaticMeshComponent->GetStaticMesh()) return Indices;
	if (!StaticMeshComponent->GetStaticMesh()->RenderData) return Indices;
	if (StaticMeshComponent->GetStaticMesh()->RenderData->LODResources.Num() > 0)
	{
		const FRawStaticIndexBuffer* IndexBuffer = &StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0].IndexBuffer;
		if (IndexBuffer)
		{
			const int32 IndexCount = IndexBuffer->GetNumIndices();
			for (int32 i = 0; i < IndexCount; i++)
			{
				const int32 Index = (int32)IndexBuffer->GetIndex(i);
				Indices.Add(Index);
			}
		}
	}

	return Indices;
}

void UExportStaticMeshToJsonBP::ExportSMDataByJsonObj(const TArray<FVector>& Vertices, const TArray<int32>& Indices, FString OutputPath, const FString Filename)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

	TSharedPtr<FJsonObject> JsonObject_data = MakeShareable(new FJsonObject);
	JsonObject->SetObjectField("data", JsonObject_data);
	JsonObject_data->SetStringField("vs_format", "...");

	TArray < TSharedPtr<FJsonValue> > IndicesValueArray;
	for (int i = 0; i < Indices.Num(); ++i)
	{
		IndicesValueArray.Add(MakeShared < FJsonValueNumber >(Indices[i]));
	}
	JsonObject_data->SetArrayField("indices", IndicesValueArray);

	TArray < TSharedPtr<FJsonValue> > VerticesJsonObj;
	for (int i = 0; i < Vertices.Num(); ++i)
	{
		TSharedPtr<FJsonObject> JsonObject_verticeElement = MakeShareable(new FJsonObject);

		JsonObject_verticeElement->SetNumberField(TEXT("X"), Vertices[i].X);
		JsonObject_verticeElement->SetNumberField(TEXT("Y"), Vertices[i].Y);
		JsonObject_verticeElement->SetNumberField(TEXT("Z"), Vertices[i].Z);

		VerticesJsonObj.Add(MakeShared<FJsonValueObject>(JsonObject_verticeElement));
	}
	JsonObject_data->SetArrayField("vertices", VerticesJsonObj);

	FString OutputString;

	typedef TJsonWriter<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriter;
	typedef TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriterFactory;
	TSharedRef<FPrettyJsonWriter> Writer = FPrettyJsonWriterFactory::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	FString Fullname = FPaths::CreateTempFilename(*OutputPath, *Filename, TEXT(".txt"));
	if (!FFileHelper::SaveStringToFile(OutputString, *Fullname, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to write to temp file: %s"), *Fullname);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Succeed to save file: %s"), *Fullname);
	}
}

void UExportStaticMeshToJsonBP::ExportSMDataByJsonWriter(const TArray<FVector>& Vertices, const TArray<int32>& Indices, FString OutputPath, const FString Filename)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString OutputString;

	typedef TJsonWriter<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriter;
	typedef TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriterFactory;
	TSharedRef<FPrettyJsonWriter> Writer = FPrettyJsonWriterFactory::Create(&OutputString);

	Writer->WriteObjectStart();
	Writer->WriteObjectStart(TEXT("data"));

	Writer->WriteArrayStart(TEXT("vs_format"));
	Writer->WriteValue(TEXT("..."));
	Writer->WriteArrayEnd();

	Writer->WriteArrayStart(TEXT("Indices"));
	for (auto i:Indices)
	{
		Writer->WriteValue(i);
	}
	Writer->WriteArrayEnd();

	Writer->WriteArrayStart(TEXT("Vertices"));
	for (auto i : Vertices)
	{
		Writer->WriteObjectStart();
		Writer->WriteValue(TEXT("X"), i.X);
		Writer->WriteValue(TEXT("Y"), i.Y);
		Writer->WriteValue(TEXT("Z"), i.Z);
		Writer->WriteObjectEnd();
	}
	Writer->WriteArrayEnd();
	Writer->WriteObjectEnd();

	Writer->WriteObjectEnd();
	Writer->Close();

	FString Fullname = FPaths::CreateTempFilename(*OutputPath, *Filename, TEXT(".txt"));
	if (!FFileHelper::SaveStringToFile(OutputString, *Fullname, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to write to temp file: %s"), *Fullname);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Succeed to save file: %s"), *Fullname);
	}
}

void UExportStaticMeshToJsonBP::ExportSMDataByJsonConverter(const TArray<FVector>& Vertices, const TArray<int32>& Indices, FString OutputPath, const FString Filename)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FStaticMeshExporterJson Data(Vertices, Indices);

	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(Data);

	FString OutputString;

	typedef TJsonWriter<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriter;
	typedef TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriterFactory;
	TSharedRef<FPrettyJsonWriter> Writer = FPrettyJsonWriterFactory::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	FString Fullname = FPaths::CreateTempFilename(*OutputPath, *Filename, TEXT(".txt"));
	if (!FFileHelper::SaveStringToFile(OutputString, *Fullname, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to write to temp file: %s"), *Fullname);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Succeed to save file: %s"), *Fullname);
	}
}
