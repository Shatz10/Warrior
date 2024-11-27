// Shatz All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWarriorInputComponent();

	template <class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,
	                           ETriggerEvent TriggerEvent, UserObject* InObject, CallbackFunc Func);

	template <class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject,
	                            CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};

template <class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                          const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent,
                                                          UserObject* InObject, CallbackFunc Func)
{
	// checkf(InInputConfig, TEXT("Input config data asset is null,can not proceed with binding");
	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, InObject, Func);
	}
}

template <class UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                    UserObject* ContextObject, CallbackFunc InputPressedFunc,
                                                    CallbackFunc InputReleasedFunc)
{
	checkf(InInputConfig, TEXT("InputConfig data asset is null, Binding not valid"));
	for (const auto Action : InInputConfig->AbilityInputActions)
	{
		if (Action.IsValid())
		{
			BindAction(Action.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, Action.InputTag);
			BindAction(Action.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc, Action.InputTag);
		}
	}
}
