// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DemoCharacterAnimInstance.h"
#include "Animations/DemoBaseAnimInstance.h"
#include "DemoHeroAnimInstance.generated.h"

class UHeroWeaponComponent;
class ARPGDemoPlayerCharacter;
/**
 * 
 */
UCLASS()
class RPGDEMO_API UDemoHeroAnimInstance : public UDemoCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	// 该函数在工作线程上工作，而不是游戏线程上工作。使用该函数计算变量是一个很大的优化.
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimaData|Reference")
	ARPGDemoPlayerCharacter* OwingHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimaData|LocomotionData")
	bool bShouldEnterRelaxState;

	// 判断站立闲置的时间，设置为5S,如果超过了五秒就说明要进入relaxed状态。
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimaData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimaData|Reference")
	TObjectPtr<UHeroWeaponComponent> OwingWeaponComponent;

	// 用于存储已经闲置的时间
	float IdleElpasedTime;
};
