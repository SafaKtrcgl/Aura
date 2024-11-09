


#include "AbilitySystem/AuraAbilitySystemLibrary.h"

#include "AbilitySystemComponent.h"
#include "Game/AuraGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/AuraHUD.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "Player/AuraPlayerState.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerController->GetHUD()))
		{
			AAuraPlayerState* PlayerState = PlayerController->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();

			const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);

			return AuraHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}

	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerController->GetHUD()))
		{
			AAuraPlayerState* PlayerState = PlayerController->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();

			const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);

			return AuraHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}

	return nullptr;
}

void UAuraAbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* AbilitySystemComponent)
{
	if (auto AuraGameMode = Cast<AAuraGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject)))
	{
		auto AvatarActor = AbilitySystemComponent->GetAvatarActor();

		const auto CharacterClassInfo = AuraGameMode->CharacterClassInfo;
		const auto ClassDefaultInfo = CharacterClassInfo->GetCharacterDefaultInfo(CharacterClass);

		auto PrimaryAttributesContextHandle =  AbilitySystemComponent->MakeEffectContext();
		PrimaryAttributesContextHandle.AddSourceObject(AvatarActor);
		const auto PrimaryAttributesSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(ClassDefaultInfo.PrimaryAttributes, Level, PrimaryAttributesContextHandle);
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*PrimaryAttributesSpecHandle.Data.Get());

		auto SecondaryAttributesContextHandle =  AbilitySystemComponent->MakeEffectContext();
		SecondaryAttributesContextHandle.AddSourceObject(AvatarActor);
		const auto SecondaryAttributesSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(CharacterClassInfo->SecondaryAttributes, Level, SecondaryAttributesContextHandle);
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SecondaryAttributesSpecHandle.Data.Get());

		auto VitalAttributesContextHandle =  AbilitySystemComponent->MakeEffectContext();
		VitalAttributesContextHandle.AddSourceObject(AvatarActor);
		const auto VitalAttributesSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(CharacterClassInfo->VitalAttributes, Level, VitalAttributesContextHandle);
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*VitalAttributesSpecHandle.Data.Get());
	}
}
