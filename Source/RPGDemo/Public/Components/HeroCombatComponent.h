// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnCombatComponent.h"
#include "GameplayTagContainer.h"
#include "HeroCombatComponent.generated.h"

class AHeroWeapon;
class UHeroWeaponComponent;
class UWeaponComponentBase;

UCLASS()
class RPGDEMO_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UHeroCombatComponent();
	
	UFUNCTION(BlueprintCallable)
	UHeroWeaponComponent* GetHeroWeaponComponent() const {return HeroWeaponComponent;};

	UFUNCTION(BlueprintCallable)
	AHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InTag) const;

	virtual UWeaponComponentBase* GetWeaponComponentBase() const override;
	
private:
	UPROPERTY(VisibleAnywhere, Category="Weapon", meta=(AllowPrivateAccess=true))
	TObjectPtr<UHeroWeaponComponent> HeroWeaponComponent;
};
