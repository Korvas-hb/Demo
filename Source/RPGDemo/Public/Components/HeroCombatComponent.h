// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class UHeroWeaponComponent;

UCLASS()
class RPGDEMO_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UHeroCombatComponent();
	UFUNCTION(BlueprintCallable)
	UHeroWeaponComponent* GetHeroWeaponComponent() const {return HeroWeaponComponent;};
	
private:
	UPROPERTY(VisibleAnywhere, Category="Weapon", meta=(AllowPrivateAccess=true))
	TObjectPtr<UHeroWeaponComponent> HeroWeaponComponent;
};
