// Fill out your copyright notice in the Description page of Project Settings.


#include "ExportCamerasAsJsonBP.h"
#include "Camera/CameraComponent.h"
#include "CameraArray.h"
#include "Kismet/GameplayStatics.h"

void UExportCamerasAsJsonBP::ExportCamera(const UObject* WorldContextObject, const UCameraComponent* CameraComponent, FString OutputPath, const FString Filename)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	FCameraData CamData;

	FTransform Trans = CameraComponent->GetComponentToWorld();
	CamData.Location = Trans.GetLocation();
	CamData.Rotator = Trans.GetRotation();
	CamData.Target = CamData.Location + CameraComponent->GetForwardVector();
	CamData.Fov = CameraComponent->FieldOfView;
	CamData.Aspect = CameraComponent->AspectRatio;

	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(CamData);
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

void UExportCamerasAsJsonBP::ExportAllCameras(const UObject* WorldContextObject, FString OutputPath, const FString Filename)
{
	if (OutputPath.IsEmpty())
	{
		OutputPath = FPaths::ProfilingDir();
	}

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