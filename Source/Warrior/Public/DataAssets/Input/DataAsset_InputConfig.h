 // Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputMappingContext.h"
#include "Engine/DataAsset.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;

USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputConfig"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;

	bool IsValid() const { return InputTag.IsValid() && InputAction; }
};


/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly,BLueprintReadOnly,meta=(TiteProperty="InputAction"))
	TArray<FWarriorInputActionConfig> NativeInputActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag", AllowPrivateAccess = "true"))
	TArray<FWarriorInputActionConfig> AbilityInputActions;


	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
};
