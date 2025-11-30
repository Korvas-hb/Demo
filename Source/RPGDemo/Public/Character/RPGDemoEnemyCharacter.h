// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGDemoCharacterBase.h"
#include "RPGDemoEnemyCharacter.generated.h"

class UDataAsset_EnemyStartUpData;
class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class RPGDEMO_API ARPGDemoEnemyCharacter : public ARPGDemoCharacterBase
{
	GENERATED_BODY()

public:
	ARPGDemoEnemyCharacter();
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }

protected:
	virtual void PossessedBy(AController* NewController) override;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<UEnemyCombatComponent> EnemyCombatComponent;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UDataAsset_EnemyStartUpData> EnemyStartUpData;
	
};
