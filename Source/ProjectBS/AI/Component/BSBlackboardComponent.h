// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BSBlackboardComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBS_API UBSBlackboardComponent : public UBlackboardComponent
{
	GENERATED_BODY()

protected:
	//~ Begin AActorComponent Interface
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~ End AActorComponent Interface
};
