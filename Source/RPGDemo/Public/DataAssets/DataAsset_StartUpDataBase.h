// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"


class URPGAbilitySystemComponent;
class URPGGameplayAbility;

UCLASS()
class RPGDEMO_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveDataAssetAbilitiesToASC(URPGAbilitySystemComponent* ASC, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<URPGGameplayAbility>> OnGivenAbilities;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<URPGGameplayAbility>> OnReactiveAbilities;

	void GrantDataAssetAbilites(const TArray<TSubclassOf<URPGGameplayAbility>> InAbilitiesGrant, URPGAbilitySystemComponent* ASC,
	                   int32 ApplyLevel = 1);
};
