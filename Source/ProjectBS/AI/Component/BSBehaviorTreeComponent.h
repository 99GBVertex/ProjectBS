// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BSBehaviorTreeComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBS_API UBSBehaviorTreeComponent : public UBehaviorTreeComponent
{
	GENERATED_BODY()

protected:
	//~ Begin AActorComponent Interface
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~ End AActorComponent Interface
};
