


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* ASComponent, const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle GameplayEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1, 8.f, FColor::Blue, FString("Effect Applied!"));
}
