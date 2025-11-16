// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGDemoCharacterBase.h"
#include "RPGDemoPlayerCharacter.generated.h"

class UHeroCombatComponent;
class UDataAsset_StartUpDataBase;
/**
 * 
 */
UCLASS()
class RPGDEMO_API ARPGDemoPlayerCharacter : public ARPGDemoCharacterBase
{
	GENERATED_BODY()

public:
	ARPGDemoPlayerCharacter();

	UHeroCombatComponent* GetHeroCombatComponent() const {return HeroCombatComponent;};
	
protected:
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

private:
	UPROPERTY(VisibleAnywhere, Category="Combat", meta=(AllowPrivateAccess=true))
	TObjectPtr<UHeroCombatComponent> HeroCombatComponent;
};
