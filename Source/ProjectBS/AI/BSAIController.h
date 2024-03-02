// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BSAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBS_API ABSAIController : public AAIController
{
	GENERATED_BODY()
	ABSAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	//~ Begin AActor Interface
	virtual void BeginPlay() override;
	//~ End AActor Interface

public:
	virtual bool RunBehaviorTree(UBehaviorTree* BTAsset) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AIController, meta = (AllowPrivateAccess = "true"))
	class UBSBlackboardComponent* BlackboardComponent;

};
