// Shatz All Rights Reserved

#pragma once
#include "AnimInstances/Hero/WarriorHeroLinkedAnimLayer.h"

#include "WarriorStructTypes.generated.h"

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};