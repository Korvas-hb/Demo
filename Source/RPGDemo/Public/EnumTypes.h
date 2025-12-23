#pragma once
UENUM()
enum class EConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EValidType : uint8
{
	Valid,
	Invalid
};

UENUM(BlueprintType)
enum class EToggleDamageType: uint8
{
	CurrentEquipWeapon,
	LeftHandEquip,
	RightHandEquip
};
