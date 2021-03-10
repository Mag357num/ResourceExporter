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
	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	FVector Location;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	FVector Target;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	FQuat Rotator;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	float Fov;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	float Aspect;

public:
	FCameraData() : Location(FVector()), Target(FVector()), Rotator(FQuat()), Fov(0.f), Aspect(0.f) {}
};