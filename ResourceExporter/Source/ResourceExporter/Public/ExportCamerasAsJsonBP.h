// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonObjectConverter.h"

#include "ExportCamerasAsJsonBP.generated.h"

/**
 * 
 */
UCLASS()
class RESOURCEEXPORTER_API UExportCamerasAsJsonBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "PluginTest", meta = (WorldContext = WorldContextObject))
	static void ExportCamera(const UObject* WorldContextObject, const UCameraComponent* CameraComponent, FString OutputPath = TEXT(""), const FString Filename = TEXT("SingleCameraData_"));

	UFUNCTION(BlueprintCallable, Category = "PluginTest", meta = (WorldContext = WorldContextObject))
	static void ExportAllCameras(const UObject* WorldContextObject, FString OutputPath = TEXT(""), const FString Filename = TEXT("AllCameraData_"));
};
