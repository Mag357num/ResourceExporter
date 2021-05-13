// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "MaterialExporterData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class RENDERDATAEXPORTER_API UMaterialExporterData : public UAssetUserData
{
	GENERATED_BODY()
public:

    UPROPERTY(EditAnywhere)
    FString ShadingModel;

    UPROPERTY(EditAnywhere)
    FString VertexShaderPath;

	UPROPERTY(EditAnywhere)
	FString PixelShaderPath;
};
