// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "DataAssets/DataAsset_InputConfig.h"
#include "RPGDemoInputComponent.generated.h"

UCLASS()
class RPGDEMO_API URPGDemoInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserClass, typename CallBackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,
	                           ETriggerEvent TriggerEvent, UserClass* Object, CallBackFunc FunctionName);

	template <class UserClass, typename CallBackFunc>
	void BindGameplayAbilityInputAction(const UDataAsset_InputConfig* InputConfig, ETriggerEvent BeginTriggerEvent,
	                                    ETriggerEvent EndTriggerEvent, UserClass* Object, CallBackFunc StartFuncName,
	                                    CallBackFunc EndFuncName);
};

template <class UserClass, typename CallBackFunc>
void URPGDemoInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                   const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent,
                                                   UserClass* Object, CallBackFunc FunctionName)
{
	checkf(InInputConfig, TEXT("请加入DataAsset"));

	if (const UInputAction* InputAction = InInputConfig->FindNativeInputAction(InInputTag))
	{
		BindAction(InputAction, TriggerEvent, Object, FunctionName);
	}
}

template <class UserClass, typename CallBackFunc>
void URPGDemoInputComponent::BindGameplayAbilityInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                            ETriggerEvent BeginTriggerEvent,
                                                            ETriggerEvent EndTriggerEvent, UserClass* Object,
                                                            CallBackFunc StartFuncName,
                                                            CallBackFunc EndFuncName)
{
	checkf(InInputConfig, TEXT("请加入DataAsset"));

	for (const auto AbilityInputAction : InInputConfig->AbilityInputActionConfigs)
	{
		if (AbilityInputAction.IsValid())
		{
			BindAction(AbilityInputAction.InputAction, BeginTriggerEvent, Object, StartFuncName,
			           AbilityInputAction.InputTag);
			BindAction(AbilityInputAction.InputAction, EndTriggerEvent, Object, EndFuncName,
			           AbilityInputAction.InputTag);
		}
	}
}
