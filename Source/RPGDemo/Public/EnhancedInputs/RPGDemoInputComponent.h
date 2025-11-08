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
	template<class UserClass,typename CallBackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,UserClass* Object, CallBackFunc FunctionName);
	
};

template <class UserClass, typename CallBackFunc>
void URPGDemoInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserClass* Object, CallBackFunc FunctionName)
{
	checkf(InInputConfig,TEXT("请加入DataAsset"));

	if (const UInputAction* InputAction	= InInputConfig->FindNativeInputAction(InInputTag))
	{
		BindAction(InputAction, TriggerEvent, Object, FunctionName);
	}
}
