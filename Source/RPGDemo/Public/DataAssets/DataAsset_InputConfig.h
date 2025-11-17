// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "StructForNeedInfo.h"
#include "DataAsset_InputConfig.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class RPGDEMO_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FDemoInputActionConfig> NativeInputActionConfigs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FDemoInputActionConfig> AbilityInputActionConfigs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UInputAction* FindNativeInputAction(const FGameplayTag& InInputTag) const;
};
