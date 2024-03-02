// Fill out your copyright notice in the Description page of Project Settings.


#include "BSEnemy.h"
#include "AI/BSAIController.h"

void ABSEnemy::BeginPlay()
{
    Super::BeginPlay();
    
    if(CharacterBT)
    {
        GetAIController()->RunBehaviorTree(CharacterBT);
    }
}
