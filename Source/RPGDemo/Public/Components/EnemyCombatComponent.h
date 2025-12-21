// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnCombatComponent.h"
#include "EnemyCombatComponent.generated.h"

class UEnemyWeaponComponent;
class UWeaponComponentBase;
/**
 * 
 */
UCLASS()
class RPGDEMO_API UEnemyCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
public:
	UEnemyCombatComponent();

	UFUNCTION(BlueprintCallable)
	UEnemyWeaponComponent* GetEnemyWeaponComponent() const {return EnemyWeaponComponent;};

	UFUNCTION(BlueprintCallable)
	AWeaponBase* GetHeroCarriedWeaponByTag(FGameplayTag InTag) const;

	virtual UWeaponComponentBase* GetWeaponComponentBase() const override;
	
private:
	UPROPERTY(VisibleAnywhere, Category="Weapon", meta=(AllowPrivateAccess=true))
	TObjectPtr<UEnemyWeaponComponent> EnemyWeaponComponent;
	
};
