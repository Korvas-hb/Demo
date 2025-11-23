// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animations/DemoBaseAnimInstance.h"
#include "HeroLinkedAnimLayer.generated.h"

class UDemoHeroAnimInstance;

UCLASS()
class RPGDEMO_API UHeroLinkedAnimLayer : public UDemoBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (NotBlueprintThreadSafe))
	UDemoHeroAnimInstance* GetHeroAnimInstance() const;
	
};
