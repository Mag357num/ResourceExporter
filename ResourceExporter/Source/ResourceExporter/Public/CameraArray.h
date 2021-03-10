// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraData.h"

#include "CameraArray.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct RESOURCEEXPORTER_API FCameraArray
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	TArray<FCameraData> Cameras;
};