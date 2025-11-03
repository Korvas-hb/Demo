// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputAction(const FGameplayTag& InInputTag) const
{
	if (!InInputTag.IsValid()) return nullptr;

	for (const auto& Item: NativeInputActionConfigs)
	{
		if (Item.InputTag == InInputTag)
		{
			return Item.InputAction;
		}
	}
	return nullptr;
}
