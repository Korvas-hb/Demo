// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "RPGDemoCharacterBase.generated.h"

class URPGAttributeSet;
class URPGAbilitySystemComponent;

UCLASS()
class RPGDEMO_API ARPGDemoCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ARPGDemoCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	URPGAttributeSet* GetRPGAttributeSet() const;
	
	
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AbilitySystem")
	TObjectPtr<URPGAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AbilitySystem")
	TObjectPtr<URPGAttributeSet> AttributeSet;

	virtual void PossessedBy(AController* NewController) override;
};
