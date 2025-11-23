// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "StructForNeedInfo.h"
#include "Weapon/WeaponBase.h"
#include "HeroWeapon.generated.h"

UCLASS()
class RPGDEMO_API AHeroWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FWeaponData GetWeaponData() const{return WeaponData;}

	UFUNCTION(BlueprintCallable)
	void SaveGrantedWeaponAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintCallable)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;
	
private:
	UPROPERTY(EditAnywhere, Category="Weapon")
	FWeaponData WeaponData;
	
	TArray<FGameplayAbilitySpecHandle> GrantedWeaponAbilitySpecHandles;
};
