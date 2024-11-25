// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "Items/Weapon/WarriorWeaponBase.h"
#include "PawnCombatComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPawnCombatComponent();

	UPROPERTY(BlueprintReadWrite, Category="Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;
	
	UFUNCTION(BlueprintCallable, Category= "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category= "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag GameplayTag) const;

	UFUNCTION(BlueprintCallable, Category="Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon() const;
private:
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeapons;
	
protected:
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
