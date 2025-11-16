// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGDEMO_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	

protected:
	// 提供获取Component的Owner
	template<typename T>
	T* GetOwningPawnFromExtensionComponent() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template Parameter get GetPawn must be the child of APawn");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return GetOwningPawnFromExtensionComponent<APawn>();
	}
	
	// 提供获取Component的拥有者的Controller。
	template<typename T>
	T* GetOwningControllerFromExtensionComponent() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Parameter get GetController must be the child of AController");
		return GetOwningPawnFromExtensionComponent<APawn>()->GetController();
	}
		
};

