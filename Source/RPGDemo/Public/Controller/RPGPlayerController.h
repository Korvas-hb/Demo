// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

struct FInputActionValue;

UCLASS()
class RPGDEMO_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

private:
	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
};
