// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StructForNeedInfo.generated.h"

class UHeroLinkedAnimLayer;
class URPGGameplayAbility;
class UInputAction;
class AWeaponBase;

// 注册武器用的数据结构
USTRUCT(BlueprintType)
struct FRegisterWeaponWithTag
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Weapon")
	TObjectPtr<AWeaponBase> RegisterWeapon;

	UPROPERTY(EditAnywhere, Category="Weapon")
	FGameplayTag RegisterTag;

	UPROPERTY(VisibleAnywhere)
	bool bRegisteredAsEquipping;

	FRegisterWeaponWithTag() : RegisterWeapon(nullptr), RegisterTag(FGameplayTag()), bRegisteredAsEquipping(false)
	{
	}

	FRegisterWeaponWithTag(AWeaponBase* InWeapon, FGameplayTag InTag, bool bRegister = false) :
		RegisterWeapon(InWeapon), RegisterTag(InTag), bRegisteredAsEquipping(bRegister)
	{
	}
};


USTRUCT(BlueprintType)
struct FDemoInputActionConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input Tag")
	FGameplayTag InputTag;

	bool IsValid() const { return InputTag.IsValid() && InputAction; };
};


USTRUCT(BlueprintType)
struct FHeroOnlyAbilitySet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<URPGGameplayAbility> InputHeroGA;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input Tag")
	FGameplayTag InputAbilityTag;

	bool IsValid() const { return InputAbilityTag.IsValid(); };
	
};

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};
