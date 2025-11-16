// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RPGGameplayAbility.generated.h"

class UPawnCombatComponent;

UENUM(BlueprintType)
enum class ERPGAbilityActivatePolicy:uint8
{
	OnGiven,
	OnTriggered
};

UCLASS()
class RPGDEMO_API URPGGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Abilities")
	ERPGAbilityActivatePolicy ActivatePolicy;

	UFUNCTION(BlueprintPure, Category="Abilities")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	
};
