// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RenderDataExporterBPLibrary.h"
#include "RenderDataExporterSettings.generated.h"

/**
 * 
 */
UCLASS(config = RenderDataExporter, defaultconfig)
class RENDERDATAEXPORTER_API URenderDataExporterSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(GlobalConfig, EditAnywhere, BlueprintReadOnly)
	float ExportUnitScale=0.01f;
	
	UPROPERTY(GlobalConfig, EditAnywhere, BlueprintReadOnly)
	FDirectoryPath ExportRootPath;

	UPROPERTY(GlobalConfig, EditAnywhere, BlueprintReadOnly)
	FString MapsFolderName=TEXT("Maps");

	UPROPERTY(GlobalConfig, EditAnywhere, BlueprintReadOnly)
	FString MeshesFolderName=TEXT("Meshes");

    UPROPERTY(GlobalConfig, EditAnywhere, BlueprintReadOnly)
    FString TexturesFolderName = TEXT("Textures");

	UPROPERTY(GlobalConfig, EditAnywhere, BlueprintReadOnly)
	bool bExportHiddenInGameMesh = true;

	UPROPERTY(GlobalConfig, EditAnywhere, BlueprintReadOnly)
	FExportStaticMeshOptions ExportStaticMeshOptions;

};
