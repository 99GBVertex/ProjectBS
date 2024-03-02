// Fill out your copyright notice in the Description page of Project Settings.


#include "BSAICharacter.h"
#include "AI/BSAIController.h"

void ABSAICharacter::BeginPlay()
{
    Super::BeginPlay();

    AIController = Cast<ABSAIController>(Controller);
}

void ABSAICharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
}

ABSAIController *ABSAICharacter::GetAIController()
{
    if (AIController.IsValid() == false)
	{
		AIController = Cast<ABSAIController>(Controller);
	}

	return AIController.Get();
}
