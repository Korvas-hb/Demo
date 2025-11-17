// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/DataAsset_StartUpDataBase.h"
#include "StructForNeedInfo.h"
#include "DataAsset_HeroStartUpData.generated.h"

UCLASS()
class RPGDEMO_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveDataAssetAbilitiesToASC(URPGAbilitySystemComponent* ASC, int32 ApplyLevel = 1) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<FHeroOnlyAbilitySet> HeroOnlyAbilities;
};
