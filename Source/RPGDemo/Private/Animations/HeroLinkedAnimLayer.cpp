// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/HeroLinkedAnimLayer.h"

#include "Animations/DemoHeroAnimInstance.h"

UDemoHeroAnimInstance* UHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UDemoHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
