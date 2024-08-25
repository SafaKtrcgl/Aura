

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/InteractableInterface.h"
#include "AuraEnemyCharacter.generated.h"

class IInteractableInterface;

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemyCharacter : public AAuraCharacterBase, public IInteractableInterface
{
	GENERATED_BODY()
	

public:
	AAuraEnemyCharacter();
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;

protected:
	virtual void BeginPlay() override;
};
