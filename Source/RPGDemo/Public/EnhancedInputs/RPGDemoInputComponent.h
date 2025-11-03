// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "RPGDemoInputComponent.generated.h"

class UDataAsset_InputConfig;
UCLASS()
class RPGDEMO_API URPGDemoInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,UObject* Object, FName FunctionName);
	
};
