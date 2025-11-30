// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/RPGGameplayAbility.h"
#include "EnemyGameplayAbility.generated.h"

class UEnemyCombatComponent;
class ARPGDemoEnemyCharacter;
/**
 * 
 */
UCLASS()
class RPGDEMO_API UEnemyGameplayAbility : public URPGGameplayAbility
{
	GENERATED_BODY()
public:
	// 敌人GA里面也需要实现对应获得敌人自己的Actor和CombatComponent
	UFUNCTION(BlueprintPure, Category="Abilities")
	ARPGDemoEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="Abilities")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ARPGDemoEnemyCharacter> CachedEnemyCharacter;
};
