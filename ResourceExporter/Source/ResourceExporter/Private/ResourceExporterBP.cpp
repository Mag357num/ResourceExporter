// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceExporterBP.h"
#include "Camera/CameraComponent.h"
#include "CameraArray.h"
#include "Kismet/GameplayStatics.h"
#include "JsonObjectConverter.h"

typedef TJsonWriter<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriter;
typedef TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriterFactory;

void UResourceExporterBP::ExportStaticMesh(const UStaticMesh* StaticMesh, FString Path, const FString& Filename)
{
	TArray<FVertexStruct> Vertices;
	GetVerticesData(StaticMesh, Vertices);

	TArray<int32> Indices;
	GetIndicesData(StaticMesh, Indices);

	FStaticMeshData Data(Vertices, Indices);

	ExportStructByJsonConverter(Data, Path, Filename);
}

void UResourceExporterBP::ExportSMDataByJsonObj(const TArray<FVertexStruct>& Vertices, const TArray<int32>& Indices, FString OutputPath, const FString& Filename)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

	TSharedPtr<FJsonObject> JsonObject_data = MakeShareable(new FJsonObject);
	JsonObject->SetObjectField("data", JsonObject_data);
	JsonObject_data->SetStringField("vs_format", "...");

	TArray<TSharedPtr<FJsonValue>> IndicesValueArray;
	for (int i = 0; i < Indices.Num(); ++i)
	{
		IndicesValueArray.Add(MakeShared<FJsonValueNumber>(Indices[i]));
	}
	JsonObject_data->SetArrayField("indices", IndicesValueArray);

	TArray<TSharedPtr<FJsonValue>> VerticesJsonObj;
	for (int i = 0; i < Vertices.Num(); ++i)
	{
		TSharedPtr<FJsonObject> JsonObject_verticeElement = MakeShareable(new FJsonObject);

		JsonObject_verticeElement->SetNumberField(TEXT("X"), Vertices[i].Position.X);
		JsonObject_verticeElement->SetNumberField(TEXT("Y"), Vertices[i].Position.Y);
		JsonObject_verticeElement->SetNumberField(TEXT("Z"), Vertices[i].Position.Z);

		VerticesJsonObj.Add(MakeShared<FJsonValueObject>(JsonObject_verticeElement));
	}
	JsonObject_data->SetArrayField("vertices", VerticesJsonObj);

	FString OutputString;

	TSharedRef<FPrettyJsonWriter> Writer = FPrettyJsonWriterFactory::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	WriteFile(OutputString, OutputPath, Filename);
}

void UResourceExporterBP::ExportSMDataByJsonWriter(const TArray<FVertexStruct>& Vertices, const TArray<int32>& Indices, FString OutputPath, const FString& Filename)
{
	FString OutputString;

	TSharedRef<FPrettyJsonWriter> Writer = FPrettyJsonWriterFactory::Create(&OutputString);

	Writer->WriteObjectStart();
	Writer->WriteObjectStart(TEXT("data"));

	Writer->WriteArrayStart(TEXT("vs_format"));
	Writer->WriteValue(TEXT("..."));
	Writer->WriteArrayEnd();

	Writer->WriteArrayStart(TEXT("Indices"));
	for (auto i : Indices)
	{
		Writer->WriteValue(i);
	}
	Writer->WriteArrayEnd();

	Writer->WriteArrayStart(TEXT("Vertices"));
	for (auto i : Vertices)
	{
		Writer->WriteObjectStart();
		Writer->WriteValue(TEXT("X"), i.Position.X);
		Writer->WriteValue(TEXT("Y"), i.Position.Y);
		Writer->WriteValue(TEXT("Z"), i.Position.Z);
		Writer->WriteObjectEnd();
	}
	Writer->WriteArrayEnd();
	Writer->WriteObjectEnd();

	Writer->WriteObjectEnd();
	Writer->Close();

	WriteFile(OutputString, OutputPath, Filename);
}

void UResourceExporterBP::WriteFile(const FString& FileString, FString OutputPath, const FString& Filename)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString Fullname = FPaths::CreateTempFilename(*OutputPath, *Filename, TEXT(".json"));
	if (!FFileHelper::SaveStringToFile(FileString, *Fullname, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to write to temp file: %s"), *Fullname);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Failed to write to temp file: %s"), *Fullname));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Succeed to save file: %s"), *Fullname);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Succeed to save file: %s"), *Fullname));
	}
}

void UResourceExporterBP::ExportCamera(const UObject* WorldContextObject, const UCameraComponent* CameraComponent, FString OutputPath, const FString& Filename)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	FCameraData CamData;

	FTransform Trans = CameraComponent->GetComponentToWorld();
	CamData.Location = Trans.GetLocation();
	CamData.Rotator = Trans.GetRotation();
	CamData.Target = CamData.Location + CameraComponent->GetForwardVector();
	CamData.Fov = CameraComponent->FieldOfView;
	CamData.Aspect = CameraComponent->AspectRatio;

	ExportStructByJsonConverter(CamData, OutputPath, Filename);
}

void UResourceExporterBP::ExportAllCameras(const UObject* WorldContextObject, FString OutputPath, const FString& Filename)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	FCameraArray Data;
	TArray<AActor*> Actors;

	UGameplayStatics::GetAllActorsOfClass(World, AActor::StaticClass(), Actors);
	for (AActor* Actor : Actors)
	{
		UActorComponent* ActCom = Actor->GetComponentByClass(UCameraComponent::StaticClass());
		if (UCameraComponent* CamCom = Cast<UCameraComponent>(ActCom))
		{
			FCameraData CamData = FCameraData();
			FTransform Trans = CamCom->GetComponentToWorld();
			CamData.Location = Trans.GetLocation();
			CamData.Rotator = Trans.GetRotation();
			CamData.Target = CamData.Location + CamCom->GetForwardVector();
			CamData.Fov = CamCom->FieldOfView;
			CamData.Aspect = CamCom->AspectRatio;
			Data.Cameras.Add(CamData);
		}
	}

	ExportStructByJsonConverter(Data, OutputPath, Filename);
}

void UResourceExporterBP::GetVerticesData(const UStaticMesh* StaticMesh, TArray<FVertexStruct>& Output)
{
	TArray<FVertexStruct> Vertices;

	if (!StaticMesh || !StaticMesh->RenderData)
	{
		return;
	}
	if (StaticMesh->RenderData->LODResources.Num() > 0)
	{
		const FStaticMeshVertexBuffers* VertexBuffers = &StaticMesh->RenderData->LODResources[0].VertexBuffers;

		if (VertexBuffers)
		{
			int32 UVChannelNum = VertexBuffers->StaticMeshVertexBuffer.GetNumTexCoords();

			for (uint32 i = 0; i < VertexBuffers->PositionVertexBuffer.GetNumVertices(); i++)
			{
				FVertexStruct Vertex;
				Vertex.Index = (int32)i;
				Vertex.Position = VertexBuffers->PositionVertexBuffer.VertexPosition(i);
				Vertex.Normal = VertexBuffers->StaticMeshVertexBuffer.VertexTangentZ(i);
				Vertex.TexCoord0 = VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 0);
				if (UVChannelNum > 1)
				{
					Vertex.TexCoord1 = VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 1);
				}
				if (UVChannelNum > 2)
				{
					Vertex.TexCoord2 = VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 2);
				}

				Vertices.Add(Vertex);
			}
		}
		else
		{
			return;
		}
	}

	Output = Vertices;
}

void UResourceExporterBP::GetIndicesData(const UStaticMesh* StaticMesh, TArray<int32>& Output)
{
	TArray<int32> Indices = TArray<int32>();

	if (!StaticMesh || !StaticMesh->RenderData)
	{
		return;
	}
	if (StaticMesh->RenderData->LODResources.Num() > 0)
	{
		const FRawStaticIndexBuffer* IndexBuffer = &StaticMesh->RenderData->LODResources[0].IndexBuffer;
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

	Output = Indices;
}
