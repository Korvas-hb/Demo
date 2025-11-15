// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGDemoCharacterBase.h"
#include "RPGDemoPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RPGDEMO_API ARPGDemoPlayerCharacter : public ARPGDemoCharacterBase
{
	GENERATED_BODY()
public:
	ARPGDemoPlayerCharacter();
	
protected:
	virtual void PossessedBy(AController* NewController) override;
};
