// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

class UDataAsset_InputConfig;
struct FInputActionValue;

UCLASS()
class RPGDEMO_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;	
	
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UDataAsset_InputConfig> InputConfig;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void OnInputAbilityPressed(FGameplayTag InInputTag);
	void OnInputAbilityReleased(FGameplayTag InInputTag);
};
