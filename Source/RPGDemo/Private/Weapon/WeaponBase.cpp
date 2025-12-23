// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponBase.h"

#include "Components/BoxComponent.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	WeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnCollisionBoxBeginOverlap);
	WeaponCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnCollisionBoxEndOverlap);
}

void AWeaponBase::OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                             const FHitResult& SweepResult)
{
	APawn* WeaponOwner = GetInstigator<APawn>();
	checkf(WeaponOwner, TEXT("Forgot to assign an instiagtor as the owning pawn of the weapon: %s"), *GetName());

	APawn* HitActor = Cast<APawn>(OtherActor);
	if (HitActor!=WeaponOwner)
	{
		OnWeaponHitTarget.ExecuteIfBound(OtherActor);
	}
	
}

void AWeaponBase::OnCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APawn* WeaponOwner = GetInstigator<APawn>();
	checkf(WeaponOwner, TEXT("Forgot to assign an instiagtor as the owning pawn of the weapon: %s"), *GetName());

	APawn* HitActor = Cast<APawn>(OtherActor);
	if (HitActor!=WeaponOwner)
	{
		OnWeaponLeaveFromHitTarget.ExecuteIfBound(OtherActor);
	}
	
}
