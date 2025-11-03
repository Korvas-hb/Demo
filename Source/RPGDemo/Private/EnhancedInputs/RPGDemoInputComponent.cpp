// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedInputs/RPGDemoInputComponent.h"

#include "DataAssets/DataAsset_InputConfig.h"

void URPGDemoInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                   const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UObject* Object, FName FunctionName)
{
	checkf(InInputConfig,TEXT("请加入DataAsset"));

	if (const UInputAction* InputAction	= InInputConfig->FindNativeInputAction(InInputTag))
	{
		BindAction(InputAction, TriggerEvent, Object, FunctionName);
	}
	
}
