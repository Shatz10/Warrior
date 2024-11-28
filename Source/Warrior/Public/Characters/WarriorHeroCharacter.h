// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "WarriorBaseCharacter.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "WarriorHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
// class UWarriorAbilitySystemComponent;
// class UWarriorAttributeSet;

UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorHeroCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UHeroCombatComponent* CombatComponent;
#pragma endregion Components

#pragma region Inputs
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(const FGameplayTag InGameplayTag);
	void Input_AbilityInputReleased(const FGameplayTag InGameplayTag);

#pragma endregion Components

public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return CombatComponent; }

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
