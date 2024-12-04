﻿// Shatz All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapon/WarriorHeroWeapon.h"


// Sets default values for this component's properties
UHeroCombatComponent::UHeroCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHeroCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InGameplayTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InGameplayTag));
}


// Called every frame
void UHeroCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

