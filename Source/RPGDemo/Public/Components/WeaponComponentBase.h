// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumTypes.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "StructForNeedInfo.h"
#include "WeaponComponentBase.generated.h"

struct FRegisterWeaponWithTag;
class AWeaponBase;

DECLARE_DELEGATE_TwoParams(FOnRegisterFinished, bool, FGameplayTag);

UCLASS()
class RPGDEMO_API UWeaponComponentBase : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Combat|Weapon")
	void RegisterSpawnedWeapon(AWeaponBase* InWeapon, FGameplayTag InWeaponTag, bool bRegisterAsEquipped = false);

	// 通过Tag来查询武器是否可以持有
	UFUNCTION(BlueprintCallable, Category="Combat|Weapon")
	AWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category="Combat|Weapon")
	FGameplayTag CurrentCharacterEquippingTag;

	// 获取到现在正在持有的武器
	UFUNCTION(BlueprintCallable, Category="Combat|Weapon")
	AWeaponBase* GetCharacterCurrentEquipWeapon() const;

	UFUNCTION(BlueprintCallable, Category="Combat|Weapon")
	void SetCurrentEquipWeaponTag(FGameplayTag InWeaponTag);

	UFUNCTION(BlueprintCallable, Category="Combat|Weapon")
	void RemoveCurrentEquipWeaponTag();

	UFUNCTION(BlueprintCallable, Category="Combat")
	void ToggleWeaponCollision(bool bShouldEnable,
	                           EToggleDamageType ToggleDamage = EToggleDamageType::CurrentEquipWeapon);

	FOnRegisterFinished OnRegisterFinished;

private:
	TArray<FRegisterWeaponWithTag> RegisterWeaponWithTagArray;
};
