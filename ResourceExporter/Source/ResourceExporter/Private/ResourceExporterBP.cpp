// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceExporterBP.h"
#include "Camera/CameraComponent.h"
#include "Math/Vector2D.h"
#include "CameraArray.h"
#include "Kismet/GameplayStatics.h"
#include "JsonObjectConverter.h"
#include "Serialization/Archive.h"
#include "Rendering/SkeletalMeshRenderData.h"

typedef TJsonWriter<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriter;
typedef TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriterFactory;

DEFINE_LOG_CATEGORY_STATIC(LogResExporter, Log, All);

void UResourceExporterBP::ExportSkeletonBinary(const USkeleton* Skeleton, FString OutputPath /*= TEXT("")*/, const FString& Filename /*= TEXT("SkeletonBinary_")*/)
{
	//if (OutputPath.IsEmpty())
	//{
	//	OutputPath = FPaths::ProfilingDir();
	//}

	//FString Fullname = OutputPath + Filename + TEXT(".dat");
	//const TCHAR* FullnameTCHAR = *Fullname;
	//FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	//FSkeletalMesh MeshTarget = GetDataFromUSkeleton(Skeleton);

	//*File << MeshTarget;

	//File->Close();
}

void UResourceExporterBP::ExportSkeletalMeshBinary(const USkeletalMesh* SkeletalMesh, FString OutputPath /*= TEXT("")*/, const FString& Filename /*= TEXT("SkeletalMeshBinary_")*/)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString Fullname = OutputPath + Filename + TEXT(".dat");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FSkeletalMesh MeshTarget = GetDataFromUSkeletalMesh(SkeletalMesh);

	*File << MeshTarget;

	File->Close();
}

void UResourceExporterBP::ExportSceneBinary(const UObject* WorldContextObject, FString OutputPath /*= TEXT("")*/, const FString& Filename /*= TEXT("Scene_")*/)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}
	FString Fullname = OutputPath + Filename + TEXT(".dat");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	FSceneBinData SceneOutput;
	TArray<AActor*> Actors; 
	FName ShowInScene(TEXT("ShowInScene"));

	UGameplayStatics::GetAllActorsOfClass(World, AActor::StaticClass(), Actors);
	for (AActor* Actor : Actors)
	{
		if (!Actor->ActorHasTag(ShowInScene)) { continue; }

		FMeshActor Indiv;
		UActorComponent* ActCom = Actor->GetComponentByClass(UStaticMeshComponent::StaticClass());
		if (UStaticMeshComponent* SMCom = Cast<UStaticMeshComponent>(ActCom))
		{
			FTransform Trans = SMCom->GetComponentToWorld();
			Indiv.MeshTrans.Translation = Trans.GetTranslation();
			//Indiv.MeshRes.Rotator = Trans.GetRotation().Euler();
			Indiv.MeshTrans.Quat = Trans.GetRotation();
			Indiv.MeshTrans.Scale = Trans.GetScale3D();

			UStaticMesh* SM = SMCom->GetStaticMesh();
			Indiv.MeshActor = GetDataFromUStaticMesh(SM);

			SceneOutput.MeshActors.Add(Indiv);
		}
	}
	int num = SceneOutput.MeshActors.Num();
	*File << SceneOutput;
	File->Close();
}

void UResourceExporterBP::ExportStaticMeshBinary(const UStaticMesh* StaticMesh, FString Path, const FString& Filename)
{
	if (Path.IsEmpty())
	{
		Path = FPaths::ProfilingDir();
	}

	FString Fullname = Path + Filename + TEXT(".dat");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FStaticMesh MeshTarget = GetDataFromUStaticMesh(StaticMesh);

	*File << MeshTarget;

	File->Close();
}

void UResourceExporterBP::ExportStaticMesh(const UStaticMesh* StaticMesh, FString Path, const FString& Filename)
{
	TArray<float> Vertices;
	GetStaticMeshVerticesData(StaticMesh, Vertices);

	TArray<int32> Indices;
	GetStaticMeshIndicesData(StaticMesh, Indices);

	FStaticMeshData Data(Vertices, Indices);

	ExportStructByJsonConverter(Data, Path, Filename);
}

void UResourceExporterBP::WriteFile(const FString& FileString, FString OutputPath, const FString& Filename)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString Fullname = OutputPath + Filename + TEXT(".json");

	if (!FFileHelper::SaveStringToFile(FileString, *Fullname, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		UE_LOG(LogResExporter, Display, TEXT("Failed to write to temp file: %s"), *Fullname);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Failed to write to temp file: %s"), *Fullname));
	}
	else
	{
		UE_LOG(LogResExporter, Error, TEXT("Succeed to save file: %s"), *Fullname);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Succeed to save file: %s"), *Fullname));
	}
}

void UResourceExporterBP::ExportCameraBinary(const UObject* WorldContextObject, const UCameraComponent* CameraComponent, FString Path, const FString& Filename)
{
	if (Path.IsEmpty())
	{
		Path = FPaths::ProfilingDir();
	}

	FString Fullname = Path + Filename + TEXT(".dat");
	const TCHAR* FullnameTCHAR = *Fullname;

	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	//UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);

	FCamera CamTarget;
	FTransform Trans = CameraComponent->GetComponentToWorld();
	CamTarget.Position = Trans.GetLocation();
	CamTarget.Dir = CameraComponent->GetForwardVector();
	CamTarget.Rotator = Trans.GetRotation().Euler();
	CamTarget.Fov = CameraComponent->FieldOfView;
	CamTarget.Aspect = CameraComponent->AspectRatio;

	*File << CamTarget;

	File->Close();
}

void UResourceExporterBP::ExportCamera(const UObject* WorldContextObject, const UCameraComponent* CameraComponent, FString OutputPath, const FString& Filename)
{
	//UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	FCameraInfo CamData;

	FTransform Trans = CameraComponent->GetComponentToWorld();
	CamData.Location = Trans.GetLocation();
	CamData.Rotator = Trans.GetRotation().Euler();
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
			FCameraInfo CamData = FCameraInfo();
			FTransform Trans = CamCom->GetComponentToWorld();
			CamData.Location = Trans.GetLocation();
			CamData.Rotator = Trans.GetRotation().Euler();
			CamData.Target = CamData.Location + CamCom->GetForwardVector();
			CamData.Fov = CamCom->FieldOfView;
			CamData.Aspect = CamCom->AspectRatio;
			Data.Cameras.Add(CamData);
		}
	}

	ExportStructByJsonConverter(Data, OutputPath, Filename);
}

void UResourceExporterBP::GetStaticMeshVerticesData(const UStaticMesh* StaticMesh, TArray<float>& Output)
{
	TArray<float> Vertices;

	if (!StaticMesh || !StaticMesh->RenderData)
	{
		return;
	}
	if (StaticMesh->RenderData->LODResources.Num() > 0)
	{
		const FStaticMeshVertexBuffers* VertexBuffers = &StaticMesh->RenderData->LODResources[0].VertexBuffers;

		if (VertexBuffers)
		{
			//int32 UVChannelNum = VertexBuffers->StaticMeshVertexBuffer.GetNumTexCoords();

			for (uint32 i = 0; i < VertexBuffers->PositionVertexBuffer.GetNumVertices(); i++)
			{
				Vertices.Add(VertexBuffers->PositionVertexBuffer.VertexPosition(i).X);
				Vertices.Add(VertexBuffers->PositionVertexBuffer.VertexPosition(i).Y);
				Vertices.Add(VertexBuffers->PositionVertexBuffer.VertexPosition(i).Z);

				Vertices.Add(VertexBuffers->StaticMeshVertexBuffer.VertexTangentZ(i).X);
				Vertices.Add(VertexBuffers->StaticMeshVertexBuffer.VertexTangentZ(i).Y);
				Vertices.Add(VertexBuffers->StaticMeshVertexBuffer.VertexTangentZ(i).Z);

				Vertices.Add(VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 0).X);
				Vertices.Add(VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 0).Y);

				// some staticmesh dont have uv1
				//Vertices.Add(VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 1).X);
				//Vertices.Add(VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 1).Y);
			}
		}
		else
		{
			return;
		}
	}

	Output = Vertices;
}

void UResourceExporterBP::GetStaticMeshIndicesData(const UStaticMesh* StaticMesh, TArray<int32>& Output)
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

void UResourceExporterBP::GetSkeletalMeshVerticesData(const USkeletalMesh* SkeletalMesh, TArray<FStaticVertex>& Output)
{
	if (!SkeletalMesh || !SkeletalMesh->GetResourceForRendering())
	{
		return;
	}
	if (SkeletalMesh->GetResourceForRendering()->LODRenderData.Num() > 0)
	{
		const FStaticMeshVertexBuffers* VertexBuffers = &SkeletalMesh->GetResourceForRendering()->LODRenderData[0].StaticVertexBuffers;

		if (VertexBuffers)
		{
			//int32 UVChannelNum = VertexBuffers->StaticMeshVertexBuffer.GetNumTexCoords();

			for (uint32 i = 0; i < VertexBuffers->PositionVertexBuffer.GetNumVertices(); i++)
			{
				FStaticVertex StaticVertex;

				StaticVertex.Position = FVector(
					VertexBuffers->PositionVertexBuffer.VertexPosition(i).X,
					VertexBuffers->PositionVertexBuffer.VertexPosition(i).Y,
					VertexBuffers->PositionVertexBuffer.VertexPosition(i).Z
				);

				StaticVertex.TangentZ = FVector(
					VertexBuffers->StaticMeshVertexBuffer.VertexTangentZ(i).X,
					VertexBuffers->StaticMeshVertexBuffer.VertexTangentZ(i).Y,
					VertexBuffers->StaticMeshVertexBuffer.VertexTangentZ(i).Z
				);

				StaticVertex.UV0 = FVector2D(
					VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 0).X,
					VertexBuffers->StaticMeshVertexBuffer.GetVertexUV(i, 0).Y
				);

				Output.Add(StaticVertex);
			}
		}
		else
		{
			return;
		}
	}
}

void UResourceExporterBP::GetSkeletalMeshWeightVerticesData(const USkeletalMesh* SkeletalMesh, TArray<FSkinnedWeightVertex>& Output)
{
	if (!SkeletalMesh || !SkeletalMesh->GetResourceForRendering())
	{
		return;
	}
	if (SkeletalMesh->GetResourceForRendering()->LODRenderData.Num() > 0)
	{
		TArray<FSkinWeightInfo> WeightVertice;
		SkeletalMesh->GetResourceForRendering()->LODRenderData[0].SkinWeightVertexBuffer.GetSkinWeights(WeightVertice);

		for (int32 i = 0; i < WeightVertice.Num(); i++)
		{
			FSkinnedWeightVertex WeightVertex;

			for (auto j : WeightVertice[i].InfluenceBones)
			{
				WeightVertex.InfluJointIndice.Add(j);
			}

			for (auto j : WeightVertice[i].InfluenceWeights)
			{
				WeightVertex.InfluJointWeights.Add(j);
			}
			Output.Add(WeightVertex);
		}
	}
}

void UResourceExporterBP::GetSkeletalMeshIndicesData(const USkeletalMesh* SkeletalMesh, TArray<uint32>& Output)
{
	if (!SkeletalMesh || !SkeletalMesh->GetResourceForRendering())
	{
		return;
	}
	if (SkeletalMesh->GetResourceForRendering()->LODRenderData.Num() > 0)
	{
		FMultiSizeIndexContainer IndexContainer = SkeletalMesh->GetResourceForRendering()->LODRenderData[0].MultiSizeIndexContainer;
		IndexContainer.GetIndexBuffer(Output);
	}
}

FStaticMesh UResourceExporterBP::GetDataFromUStaticMesh(const UStaticMesh* SM)
{
	FStaticMesh MeshTarget;
	TArray<float> Vertices;
	GetStaticMeshVerticesData(SM, Vertices);
	TArray<int32> Indices;
	GetStaticMeshIndicesData(SM, Indices);

	for (int32 i = 0; i < Vertices.Num(); i++)
	{
		FStaticVertex OneVertex;
		OneVertex.Position = FVector(Vertices[i], Vertices[i + 1], Vertices[i + 2]);
		OneVertex.TangentZ = FVector(Vertices[i + 3], Vertices[i + 4], Vertices[i + 5]);
		OneVertex.UV0 = FVector2D(Vertices[i + 6], Vertices[i + 7]);
		OneVertex.Color = FVector4(1.0f, 1.0f, 1.0f, 1.0f);

		MeshTarget.Vertice.Add(OneVertex); // TODO: push a stack obj or heap obj? will it be release? tried and found out it wont be release, but still dk is it correct.
		i += 7;
	}
	MeshTarget.Indices = MoveTemp(Indices);
	MeshTarget.VertStride = 48; // TODO: sth wrong with sizeof(FVector3), should get 56, but get 64. record: change to 48 becuz remove of uv1
	////0.12.24.32.48.64.
	//UE_LOG(LogTemp, Warning, TEXT("%d.%d.%d.%d.%d.%d."), offsetof(FVertex, Position), offsetof(FVertex, TangentZ), offsetof(FVertex, UV0), offsetof(FVertex, UV1), offsetof(FVertex, Color));
	//UE_LOG(LogTemp, Warning, TEXT("%d.%d.%d"), sizeof(FVector), sizeof(FVector2D), sizeof(FVector4));
	return MeshTarget;
}

FSkeletalMesh UResourceExporterBP::GetDataFromUSkeletalMesh(const USkeletalMesh* SM)
{
	FSkeletalMesh MeshTarget;

	GetSkeletalMeshVerticesData(SM, MeshTarget.Vertice);
	GetSkeletalMeshWeightVerticesData(SM, MeshTarget.SkinnedWeightVertice);
	GetSkeletalMeshIndicesData(SM, MeshTarget.Indices);
	MeshTarget.VertStride = 48;

	return MeshTarget;
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

