// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animations/DemoBaseAnimInstance.h"
#include "DemoCharacterAnimInstance.generated.h"

class ARPGDemoCharacterBase;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class RPGDEMO_API UDemoCharacterAnimInstance : public UDemoBaseAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	ARPGDemoCharacterBase* OwingCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwingMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimaData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimaData|LocomotionData")
	bool bHasAcceleration;
};
