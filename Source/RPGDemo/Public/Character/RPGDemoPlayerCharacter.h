// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGDemoCharacterBase.h"
#include "Interfaces/PawnComponentInterface.h"
#include "RPGDemoPlayerCharacter.generated.h"

class UHeroCombatComponent;
class UDataAsset_StartUpDataBase;
/**
 * 
 */
UCLASS()
class RPGDEMO_API ARPGDemoPlayerCharacter : public ARPGDemoCharacterBase,public IPawnComponentInterface
{
	GENERATED_BODY()

public:
	ARPGDemoPlayerCharacter();

	UHeroCombatComponent* GetHeroCombatComponent() const {return HeroCombatComponent;}

	UFUNCTION(BlueprintPure)
	UHeroCombatComponent* K2_GetHeroCombatComponent() const {return HeroCombatComponent;}

	// ~Begin IPawnCombatInterface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	// ~End
	
protected:
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

private:
	UPROPERTY(VisibleAnywhere, Category="Combat", meta=(AllowPrivateAccess=true))
	TObjectPtr<UHeroCombatComponent> HeroCombatComponent;
};
