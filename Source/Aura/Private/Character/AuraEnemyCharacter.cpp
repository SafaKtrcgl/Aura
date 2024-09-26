


#include "Character/AuraEnemyCharacter.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include <AbilitySystem/AuraAttributeSet.h>

void AAuraEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->SetCustomDepthStencilValue(250);
	Weapon->SetCustomDepthStencilValue(250);

	InitAbilityActorInfo();
}

void AAuraEnemyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void AAuraEnemyCharacter::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
