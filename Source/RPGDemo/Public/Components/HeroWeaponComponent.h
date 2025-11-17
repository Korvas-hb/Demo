// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "StructForNeedInfo.h"
#include "HeroWeaponComponent.generated.h"

class AWeaponBase;

UCLASS()
class RPGDEMO_API UHeroWeaponComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Combat|Weapon")
	void RegisterSpawnedWeapon(AWeaponBase* InWeapon, FGameplayTag InWeaponTag, bool bRegisterAsEquipped = false);

	// 通过Tag来查询武器是否可以持有
	UFUNCTION(BlueprintCallable, Category="Combat|Weapon")
	AWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadOnly, Category="Combat|Weapon")
	FGameplayTag CurrentCharacterEquippingTag;

	// 获取到现在正在持有的武器
	UFUNCTION(BlueprintCallable, Category="Combat|Weapon")
	AWeaponBase* GetCharacterCurrentEquipWeapon() const;

private:
	TArray<FRegisterWeaponWithTag> RegisterWeaponWithTagArray;
};
