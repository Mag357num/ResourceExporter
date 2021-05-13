// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math\Quat.h"

#include "CameraData.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct RESOURCEEXPORTER_API FCameraInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	FVector Location;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	FVector Target;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	FVector Rotator;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	float Fov;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	float Aspect;

public:
	FCameraInfo() : Location(FVector()), Target(FVector()), Rotator(FVector()), Fov(0.f), Aspect(0.f) {}
};