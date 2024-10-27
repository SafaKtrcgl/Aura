

#include "Input/AuraInputConfig.h"
#include "InputAction.h"


const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (auto abilityInputAction : AbilityInputActions)
	{
		if (abilityInputAction.InputAction && abilityInputAction.InputTag == InputTag)
		{
			return abilityInputAction.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find any input for input tag: [%s] on input config [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}
	return nullptr;
}
