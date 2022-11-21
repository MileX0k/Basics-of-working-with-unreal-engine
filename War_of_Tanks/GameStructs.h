// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStructs.generated.h"

UENUM(BlueprintType)
enum class ECannonType : uint8
{
	FireTrace = 0 UMETA(DisplayName = "Use trace"),
	FireProjectile = 1 UMETA(DisplayName = "Use projectile")
};



UCLASS()
class WAR_OF_TANKS_1_0_API UGameStructs : public UObject
{
	GENERATED_BODY()
	
};
