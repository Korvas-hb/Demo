// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/RPGGameplayAbility.h"
#include "HeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class ARPGPlayerController;
class ARPGDemoPlayerCharacter;

UCLASS()
class RPGDEMO_API UHeroGameplayAbility : public URPGGameplayAbility
{
	GENERATED_BODY()

public:
	// 自己GA里面提供三个函数分别可以获取自己Owner的Character，Controller和其自己的战斗系统.
	UFUNCTION(BlueprintPure, Category="Abilities")
	ARPGDemoPlayerCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="Abilities")
	ARPGPlayerController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category="Abilities")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ARPGDemoPlayerCharacter> CachedHeroCharacter;
	TWeakObjectPtr<ARPGPlayerController> CachedHeroController;
};
