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
	// 自己有的原生按键 Action和标签
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FDemoInputActionConfig> NativeInputActionConfigs;

	// 要按键触发的技能的GA的Action和标签
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FDemoInputActionConfig> AbilityInputActionConfigs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UInputAction* FindNativeInputAction(const FGameplayTag& InInputTag) const;
};
