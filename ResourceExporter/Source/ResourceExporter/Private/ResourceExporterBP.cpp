// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceExporterBP.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"
#include "Math/Vector2D.h"
#include "CameraArray.h"
#include "Kismet/GameplayStatics.h"
#include "JsonObjectConverter.h"
#include "Serialization/Archive.h"
#include "Rendering/SkeletalMeshRenderData.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/PointLightComponent.h"

typedef TJsonWriter<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriter;
typedef TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> FPrettyJsonWriterFactory;

DEFINE_LOG_CATEGORY_STATIC(LogResExporter, Log, All);

void UResourceExporterBP::ExportSequenceBinary(UAnimSequence* Sequence, FString OutputPath /*= TEXT("")*/, const FString& Filename /*= TEXT("SequenceBinary_")*/)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString Fullname = OutputPath + Filename + TEXT(".dat");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FSequence_RE Target = GetDataFromUAnimSequence(Sequence);

	*File << Target;

	File->Close();
}

void UResourceExporterBP::ExportSkeletonBinary(const USkeleton* Skeleton, FString OutputPath /*= TEXT("")*/, const FString& Filename /*= TEXT("SkeletonBinary_")*/)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString Fullname = OutputPath + Filename + TEXT(".dat");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FSkeleton_RE Target = GetDataFromUSkeleton(Skeleton);

	*File << Target;

	File->Close();
}

void UResourceExporterBP::ExportSkeletalMesh_Lod0_Binary(const USkeletalMesh* SkeletalMesh, FString OutputPath /*= TEXT("")*/, const FString& Filename /*= TEXT("SkeletalMeshBinary_")*/)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString Fullname = OutputPath + Filename + TEXT(".dat");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FSkeletalMesh_Lod_RE Target = GetDataFromUSkeletalMesh(SkeletalMesh);

	*File << Target;

	File->Close();
}

UWorld* UResourceExporterBP::CastToWorld(UObject* Object)
{
	return Cast<UWorld>(Object);
}

void UResourceExporterBP::ExportSceneActors(UWorld* World, FString OutputPath /*= TEXT("")*/, const FString& Filename /*= TEXT("Scene_")*/)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}
	FString Fullname = OutputPath + Filename + TEXT(".scene");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FScene_RE SceneOutput;
	FName ExportTag(TEXT("Export"));

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(World, AActor::StaticClass(), Actors);
	for (AActor* Actor : Actors)
	{
		if (!Actor->ActorHasTag(ExportTag)) { continue; }

		AActor_RE ActorExport;
		ActorExport.Name = Actor->GetFName().ToString();

		if (Cast<UCameraComponent>(Actor->GetRootComponent()->GetChildComponent(0)))
		{
			ActorExport.Type = EActorType::CAMERA_ACTOR;
		}
		else if (Cast<UDirectionalLightComponent>(Actor->GetRootComponent()))
		{
			ActorExport.Type = EActorType::DIRECTIONALLIGHT_ACTOR;
		}
		else if (Cast<UPointLightComponent>(Actor->GetRootComponent()))
		{
			ActorExport.Type = EActorType::POINTLIGHT_ACTOR;
		}
		else if (Cast<UStaticMeshComponent>(Actor->GetRootComponent()))
		{
			ActorExport.Type = EActorType::STATICMESH_ACTOR;
		}
		else if (Cast<USkeletalMeshComponent>(Actor->GetRootComponent()))
		{
			ActorExport.Type = EActorType::SKELETALMESH_ACTOR;
		}
		else
		{
			ActorExport.Type = EActorType::UNKNOW;
		}

		// camera components
		{
			auto Components = Actor->GetComponentsByClass(UCameraComponent::StaticClass());
			for (auto i : Components)
			{
				UCameraComponent* Component = Cast<UCameraComponent>(i);
				FCameraComponent_RE ComponentExport;

				// bouding
				ComponentExport.Bounding = FBoxSphereBounds_RE(Component->Bounds);

				// transform
				FTransform Trans = Component->GetComponentToWorld();
				ComponentExport.Transform.Translation = Trans.GetTranslation();
				ComponentExport.Transform.Quat = Trans.GetRotation();
				ComponentExport.Transform.Scale = Trans.GetScale3D();

				// other parameters
				ComponentExport.ProjectionMode = 0;
				ComponentExport.FieldOfView = Component->FieldOfView;
				ComponentExport.AspectRatio = Component->AspectRatio;
				ComponentExport.OrthoWidth = Component->OrthoWidth;

				ActorExport.CamComponents.Add(ComponentExport);
			}
		}

		// direcitonal light components
		{
			auto Components = Actor->GetComponentsByClass(UDirectionalLightComponent::StaticClass());
			for (auto i : Components)
			{
				UDirectionalLightComponent* Component = Cast<UDirectionalLightComponent>(i);
				FDirectionalLightComponent_RE ComponentExport;

				// bouding
				ComponentExport.Bounding = FBoxSphereBounds_RE(Component->Bounds);

				// transform
				FTransform Trans = Component->GetComponentToWorld();
				ComponentExport.Transform.Translation = Trans.GetTranslation();
				ComponentExport.Transform.Quat = Trans.GetRotation();
				ComponentExport.Transform.Scale = Trans.GetScale3D();

				// color
				ComponentExport.LightColor = Component->GetLightColor();

				// other parameters
				ComponentExport.Intensity = Component->Intensity;

				ActorExport.DLightComponents.Add(ComponentExport);
			}
		}

		// point light components
		{
			auto Components = Actor->GetComponentsByClass(UPointLightComponent::StaticClass());
			for (auto i : Components)
			{
				UPointLightComponent* Component = Cast<UPointLightComponent>(i);
				FPointLightComponent_RE ComponentExport;

				// bouding
				ComponentExport.Bounding = FBoxSphereBounds_RE(Component->Bounds);

				// transform
				FTransform Trans = Component->GetComponentToWorld();
				ComponentExport.Transform.Translation = Trans.GetTranslation();
				ComponentExport.Transform.Quat = Trans.GetRotation();
				ComponentExport.Transform.Scale = Trans.GetScale3D();

				// color
				ComponentExport.LightColor = Component->GetLightColor();

				// other parameters
				ComponentExport.Intensity = Component->Intensity;
				ComponentExport.AttenuationRadius = Component->AttenuationRadius;
				ComponentExport.SourceRadius = Component->SourceRadius;

				ActorExport.PLightComponents.Add(ComponentExport);
			}
		}

		// static mesh components
		{
			auto Components = Actor->GetComponentsByClass(UStaticMeshComponent::StaticClass());
			for (auto i : Components)
			{
				UStaticMeshComponent* Component = Cast<UStaticMeshComponent>(i);
				FStiaticMeshComponent_RE ComponentExport;

				// bouding
				ComponentExport.Bounding = FBoxSphereBounds_RE(Component->Bounds);

				// staticmesh lod
				UStaticMesh* SM = Component->GetStaticMesh();
				ComponentExport.StaticMesh = GetLod0DataFromUStaticMesh(SM);

				// transform
				FTransform Trans = Component->GetComponentToWorld();
				ComponentExport.Transform.Translation = Trans.GetTranslation();
				ComponentExport.Transform.Quat = Trans.GetRotation();
				ComponentExport.Transform.Scale = Trans.GetScale3D();

				// material
				for (int32 j = 0; j < Component->GetNumMaterials(); j++)
				{
					FMaterialInfo_RE Mat;
					Mat.MaterialName = Component->GetMaterial(j)->GetFName().ToString();
					Mat.IsMaterialInstance = Cast<UMaterialInstance>(Component->GetMaterial(j)) != nullptr;
					ComponentExport.Materials.Add(Mat);
				}
				ActorExport.SMComponents.Add(ComponentExport);
			}
		}

		// skeletal mesh components
		{
			auto Components = Actor->GetComponentsByClass(USkeletalMeshComponent::StaticClass());
			for (auto i : Components)
			{
				USkeletalMeshComponent* Component = Cast<USkeletalMeshComponent>(i);
				FSkeletalMeshComponent_RE ComponentExport;

				// bouding
				ComponentExport.Bounding = FBoxSphereBounds_RE(Component->Bounds);

				// skeletalmesh lod
				USkeletalMesh* SKM = Component->SkeletalMesh;
				ComponentExport.SkeletalMesh = GetDataFromUSkeletalMesh(SKM);

				// transform
				FTransform Trans = Component->GetComponentToWorld();
				ComponentExport.Transform.Translation = Trans.GetTranslation();
				ComponentExport.Transform.Quat = Trans.GetRotation();
				ComponentExport.Transform.Scale = Trans.GetScale3D();

				// skeleton
				USkeleton* Skeleton = SKM->Skeleton;
				ComponentExport.Skeleton = GetDataFromUSkeleton(Skeleton);

				// sequence
				//for (int32 j = 0; j < Component->GetAnimInstance()->; j++)
				//{

				//}

				// material
				for (int32 j = 0; j < Component->GetNumMaterials(); j++)
				{
					FMaterialInfo_RE Mat;
					Mat.MaterialName = Component->GetMaterial(j)->GetFName().ToString();
					Mat.IsMaterialInstance = Cast<UMaterialInstance>(Component->GetMaterial(j)) != nullptr;
					ComponentExport.Materials.Add(Mat);
				}
				ActorExport.SKMComponents.Add(ComponentExport);
			}
		}

		SceneOutput.Actors.Add(ActorExport);
	}
	*File << SceneOutput;
	File->Close();
}

void UResourceExporterBP::ExportMaterial(UMaterial* Material, FString OutputPath /*= TEXT("")*/)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString Fullname = OutputPath + Material->GetFName().ToString() + TEXT(".material");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FMaterial_RE Mat;
	Mat.MaterialName = Material->GetFName().ToString();
	Mat.ShaderFileName = "Resource\\Shader\\" + Mat.MaterialName + ".shader";

	switch (Material->GetBlendMode())
	{
	case EBlendMode::BLEND_Additive:
		Mat.BlendMode = EBlendMode_RE::ADDITIVE_BM;
		break;
	case EBlendMode::BLEND_AlphaComposite:
		Mat.BlendMode = EBlendMode_RE::ALPHACOMPOSITE_BM;
		break;
	case EBlendMode::BLEND_AlphaHoldout:
		Mat.BlendMode = EBlendMode_RE::ALPHAHOLDOUT_BM;
		break;
	case EBlendMode::BLEND_Masked:
		Mat.BlendMode = EBlendMode_RE::MASKED_BM;
		break;
	case EBlendMode::BLEND_Modulate:
		Mat.BlendMode = EBlendMode_RE::MODULATE_BM;
		break;
	case EBlendMode::BLEND_Opaque:
		Mat.BlendMode = EBlendMode_RE::OPAQUE_BM;
		break;
	case EBlendMode::BLEND_Translucent:
		Mat.BlendMode = EBlendMode_RE::TRANSLUCENT_BM;
		break;
	default:
		break;
	}

	// scalar
	TArray<FMaterialParameterInfo> ParameterInfos;
	TArray<FGuid> Guids;
	Material->GetAllScalarParameterInfo(ParameterInfos, Guids);
	for (auto j : ParameterInfos)
	{
		float Scalar;
		Material->GetScalarParameterValue(j.Name, Scalar);
		Mat.ScalarParams.Add(Scalar);
	}

	// vector
	Material->GetAllVectorParameterInfo(ParameterInfos, Guids);
	for (auto j : ParameterInfos)
	{
		FLinearColor Vector;
		Material->GetVectorParameterValue(j.Name, Vector);
		Mat.VectorParams.Add(Vector);
	}

	// texture
	TArray<UTexture*> UsedTextures;
	Material->GetUsedTextures(UsedTextures, EMaterialQualityLevel::High, true, ERHIFeatureLevel::SM5, true);
	for (auto j : UsedTextures)
	{
		Mat.TextureParams.Add(j->GetFName().ToString());
	}

	*File << Mat;

	File->Close();
}

void UResourceExporterBP::ExportMaterialInstance(UMaterialInstance* MaterialInstance, FString OutputPath/* = TEXT("")*/)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	FString Fullname = OutputPath + MaterialInstance->GetFName().ToString() + TEXT(".matins");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FMaterialInstance_RE Mat;
	Mat.MaterialInstanceName = MaterialInstance->GetFName().ToString();
	Mat.BaseMaterialName = MaterialInstance->GetBaseMaterial()->GetFName().ToString();

	// scalar
	TArray<FMaterialParameterInfo> ParameterInfos;
	TArray<FGuid> Guids;
	MaterialInstance->GetAllScalarParameterInfo(ParameterInfos, Guids);
	for (auto j : ParameterInfos)
	{
		float Scalar;
		MaterialInstance->GetScalarParameterValue(j.Name, Scalar);
		Mat.ScalarParams.Add(Scalar);
	}

	// vector
	MaterialInstance->GetAllVectorParameterInfo(ParameterInfos, Guids);
	for (auto j : ParameterInfos)
	{
		FLinearColor Vector;
		MaterialInstance->GetVectorParameterValue(j.Name, Vector);
		Mat.VectorParams.Add(Vector);
	}

	// texture
	TArray<UTexture*> UsedTextures;
	MaterialInstance->GetUsedTextures(UsedTextures, EMaterialQualityLevel::High, true, ERHIFeatureLevel::SM5, true);
	for (auto j : UsedTextures)
	{
		Mat.TextureParams.Add(j->GetFName().ToString());
	}

	*File << Mat;

	File->Close();
}

void UResourceExporterBP::ExportStaticMesh_Lod0_Binary(const UStaticMesh* StaticMesh, FString Path, const FString& Filename)
{
	if (Path.IsEmpty())
	{
		Path = FPaths::ProfilingDir();
	}

	FString Fullname = Path + Filename + TEXT(".dat");
	const TCHAR* FullnameTCHAR = *Fullname;
	FArchive* File = IFileManager::Get().CreateFileWriter(FullnameTCHAR, 0);

	FStaticMesh_Lod_RE Target = GetLod0DataFromUStaticMesh(StaticMesh);

	*File << Target;

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

	FCamera_RE CamTarget;
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

void UResourceExporterBP::GetSkeletalMeshVerticesData(const USkeletalMesh* SkeletalMesh, TArray<FStaticVertex_RE>& Output)
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

			Output.Reset();
			for (uint32 i = 0; i < VertexBuffers->PositionVertexBuffer.GetNumVertices(); i++)
			{
				FStaticVertex_RE StaticVertex;

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

				StaticVertex.Color = FVector4(1.f, 1.f, 1.f, 1.f);

				Output.Add(StaticVertex);
			}
		}
		else
		{
			return;
		}
	}
}

void UResourceExporterBP::GetSkeletalMeshWeightVerticesData(const USkeletalMesh* SkeletalMesh, TArray<FSkinnedWeightVertex_RE>& Output)
{
	if (!SkeletalMesh || !SkeletalMesh->GetResourceForRendering())
	{
		return;
	}
	if (SkeletalMesh->GetResourceForRendering()->LODRenderData.Num() > 0)
	{
		TArray<FSkinWeightInfo> WeightVertice;
		SkeletalMesh->GetResourceForRendering()->LODRenderData[0].SkinWeightVertexBuffer.GetSkinWeights(WeightVertice);
		
		Output.Reset();
		for (int32 i = 0; i < WeightVertice.Num(); i++)
		{
			FSkinnedWeightVertex_RE WeightVertex;

			uint32 SectionNum = SkeletalMesh->GetResourceForRendering()->LODRenderData[0].RenderSections.Num();
			uint32 SectionIndex = SectionNum - 1;
			for (uint32 k = 0; k < SectionNum - 1; k++)
			{
				int32 BaseIndex = SkeletalMesh->GetResourceForRendering()->LODRenderData[0].RenderSections[k + 1].BaseIndex;
				if (i < BaseIndex)
				{
					SectionIndex = k;
					break;
				}
			}

			for (auto j : WeightVertice[i].InfluenceBones)
			{
				uint32 GlobalIndex = SkeletalMesh->GetResourceForRendering()->LODRenderData[0].RenderSections[SectionIndex].BoneMap[j];
				WeightVertex.InfluJointIndice.Add(GlobalIndex);
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
		Output.Reset();
		SkeletalMesh->GetResourceForRendering()->LODRenderData[0].MultiSizeIndexContainer.GetIndexBuffer(Output);
	}
}

void UResourceExporterBP::GetSkeletonJointsData(const USkeleton* Skeleton, TArray<FJoint_RE>& Output)
{
	if (!Skeleton)
	{
		return;
	}

	Output.Reset();
	for (auto i : Skeleton->GetReferenceSkeleton().GetRawRefBoneInfo())
	{
		FJoint_RE Joint;
		Joint.Name = i.Name.ToString();
		Joint.ParentIndex = i.ParentIndex;
		Output.Add(Joint);
	}
}

void UResourceExporterBP::GetSkeletonBindPoseData(const USkeleton* Skeleton, TArray<FTransform>& Output)
{
	if (!Skeleton)
	{
		return;
	}
	Output.Reset();
	Output = Skeleton->GetReferenceSkeleton().GetRawRefBonePose();
}

void UResourceExporterBP::GetSkeletonNameIndexMap(const USkeleton* Skeleton, int32 JointNum, TMap<FString, int32>& Output)
{
	if (!Skeleton)
	{
		return;
	}
	Output.Reset();
	for (int32 i = 0; i < JointNum; i++)
	{
		FString JointName = Skeleton->GetReferenceSkeleton().GetBoneName(i).ToString();
		Output.Add(TTuple<FString, int32>(JointName, i));
	}
}

void UResourceExporterBP::GetSequenceLengthData(UAnimSequence* Sequence, float& Output)
{
	if (!Sequence)
	{
		return;
	}

	Output = Sequence->GetMaxCurrentTime();
}

void UResourceExporterBP::GetSequenceFrameNumData(const UAnimSequence* Sequence, uint32& Output)
{
	if (!Sequence)
	{
		return;
	}

	Output = Sequence->GetRawNumberOfFrames();
}

void UResourceExporterBP::GetSequenceTracksData(const UAnimSequence* Sequence, TArray<FTrack_RE>& Output)
{
	if (!Sequence)
	{
		return;
	}

	TArray<FRawAnimSequenceTrack> UETracks = Sequence->GetRawAnimationData();

	Output.Reset();
	for (int32 i = 0; i < UETracks.Num(); i++)
	{
		FTrack_RE Track;
		Track.Scales = UETracks[i].ScaleKeys;
		Track.Quaternions = UETracks[i].RotKeys;
		Track.Translations = UETracks[i].PosKeys;

		Output.Add(Track);
	}
}

void UResourceExporterBP::GetSequenceTrackJointMapTableData(const UAnimSequence* Sequence, TArray<int32>& Output)
{
	if (!Sequence)
	{
		return;
	}

	Output.Reset();
	for (auto i : Sequence->GetRawTrackToSkeletonMapTable())
	{
		Output.Add(i.BoneTreeIndex);
	}
}

FStaticMesh_Lod_RE UResourceExporterBP::GetLod0DataFromUStaticMesh(const UStaticMesh* SM)
{
	FStaticMesh_Lod_RE Target;
	TArray<float> Vertices;
	GetStaticMeshVerticesData(SM, Vertices);
	TArray<int32> Indices;
	GetStaticMeshIndicesData(SM, Indices);

	for (int32 i = 0; i < Vertices.Num(); i++)
	{
		FStaticVertex_RE OneVertex;
		OneVertex.Position = FVector(Vertices[i], Vertices[i + 1], Vertices[i + 2]);
		OneVertex.TangentZ = FVector(Vertices[i + 3], Vertices[i + 4], Vertices[i + 5]);
		OneVertex.UV0 = FVector2D(Vertices[i + 6], Vertices[i + 7]);
		OneVertex.Color = FVector4(1.0f, 1.0f, 1.0f, 1.0f);

		Target.Vertice.Add(OneVertex); // TODO: push a stack obj or heap obj? will it be release? tried and found out it wont be release, but still dk is it correct.
		i += 7;
	}
	Target.Indices = MoveTemp(Indices);
	Target.VertStride = 48; // TODO: sth wrong with sizeof(FVector3), should get 56, but get 64. record: change to 48 becuz remove of uv1
	////0.12.24.32.48.64.
	//UE_LOG(LogTemp, Warning, TEXT("%d.%d.%d.%d.%d.%d."), offsetof(FVertex, Position), offsetof(FVertex, TangentZ), offsetof(FVertex, UV0), offsetof(FVertex, UV1), offsetof(FVertex, Color));
	//UE_LOG(LogTemp, Warning, TEXT("%d.%d.%d"), sizeof(FVector), sizeof(FVector2D), sizeof(FVector4));
	return Target;
}

FSkeletalMesh_Lod_RE UResourceExporterBP::GetDataFromUSkeletalMesh(const USkeletalMesh* SM)
{
	FSkeletalMesh_Lod_RE Target;

	Target.VertStride = 48;
	GetSkeletalMeshVerticesData(SM, Target.Vertice);
	GetSkeletalMeshWeightVerticesData(SM, Target.SkinnedWeightVertice);
	GetSkeletalMeshIndicesData(SM, Target.Indices);

	return Target;
}

RE::FSkeleton_RE UResourceExporterBP::GetDataFromUSkeleton(const USkeleton* Sk)
{
	FSkeleton_RE Target;

	GetSkeletonJointsData(Sk, Target.Joints);
	GetSkeletonBindPoseData(Sk, Target.BindPose);
	GetSkeletonNameIndexMap(Sk, Target.Joints.Num(), Target.NameToIndexMap);

	return Target;
}

RE::FSequence_RE UResourceExporterBP::GetDataFromUAnimSequence(UAnimSequence* Se)
{
	FSequence_RE Target;

	GetSequenceLengthData(Se, Target.SequenceLength);
	GetSequenceFrameNumData(Se, Target.NumFrames);
	GetSequenceTracksData(Se, Target.JointTracks);
	GetSequenceTrackJointMapTableData(Se, Target.TrackToJointIndexMapTable);

	return Target;
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

