// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math\Quat.h"

#include "CameraData.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct RESOURCEEXPORTER_API FCameraData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "PluginTest")
	FVector Location;

	UPROPERTY(BlueprintReadOnly, Category = "PluginTest")
	FVector Target;

	UPROPERTY(BlueprintReadOnly, Category = "PluginTest")
	FQuat Rotator;

	UPROPERTY(BlueprintReadOnly, Category = "PluginTest")
	float Fov;

	UPROPERTY(BlueprintReadOnly, Category = "PluginTest")
	float Aspect;

public:
	FCameraData() : Location(FVector()), Target(FVector()), Rotator(FQuat()), Fov(0.f), Aspect(0.f) {}
};