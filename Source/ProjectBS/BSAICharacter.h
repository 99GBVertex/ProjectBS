// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BSCharacter.h"
#include "BSAICharacter.generated.h"

class ABSAIController;
/**
 * 
 */
UCLASS()
class PROJECTBS_API ABSAICharacter : public ABSCharacter
{
	GENERATED_BODY()

protected:
	//~ Begin AActor Interface
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~ End AActor Interface

public:
	ABSAIController* GetAIController();

public:
	UPROPERTY(EditAnyWhere, category = "BS AI")
	class UBehaviorTree* CharacterBT;

protected:
	UPROPERTY(VisibleAnyWhere, category = "BS AI")
	TWeakObjectPtr<ABSAIController> AIController;
};
