// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/PathFollowingComponent.h"
#include "BSPathFollowingComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBS_API UBSPathFollowingComponent : public UPathFollowingComponent
{
	GENERATED_BODY()

protected:
	//~ Begin AActorComponent Interface
	virtual void BeginPlay() override;
	//~ End AActorComponent Interface
};
