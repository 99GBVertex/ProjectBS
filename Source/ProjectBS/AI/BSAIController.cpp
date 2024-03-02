// Fill out your copyright notice in the Description page of Project Settings.


#include "BSAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Component/BSBehaviorTreeComponent.h"
#include "Component/BSBlackboardComponent.h"
#include "Component/BSPathFollowingComponent.h"

ABSAIController::ABSAIController(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/) :
	Super(ObjectInitializer.SetDefaultSubobjectClass(TEXT("PathFollowingComponent"), UBSPathFollowingComponent::StaticClass()))
{
	BlackboardComponent = CreateDefaultSubobject<UBSBlackboardComponent>(TEXT("BlackboardComponent"));
}

void ABSAIController::BeginPlay()
{
    Super::BeginPlay();
}

bool ABSAIController::RunBehaviorTree(UBehaviorTree* BTAsset)
{
    if(BTAsset == nullptr)
    {
        return false;
    }

    bool bSuccess = true;

    // see if need a blackboard component at all
    UBlackboardComponent* BlackboardComp = Blackboard;
    if (BTAsset->BlackboardAsset && (Blackboard == nullptr || Blackboard->IsCompatibleWith(BTAsset->BlackboardAsset) == false))
    {
        bSuccess = UseBlackboard(BTAsset->BlackboardAsset, BlackboardComp);
    }

    if (bSuccess)
    {
        BlackboardComp->SetValueAsVector(TEXT("TargetLocation"), FVector::ZeroVector);
        UBSBehaviorTreeComponent* BTComp = Cast<UBSBehaviorTreeComponent>(BrainComponent);
        if (BTComp == NULL)
        {
            UE_VLOG(this, LogBehaviorTree, Log, TEXT("RunBehaviorTree: spawning BehaviorTreeComponent.."));

            BTComp = NewObject<UBSBehaviorTreeComponent>(this, TEXT("BTComponent"));
            BTComp->RegisterComponent();
            REDIRECT_OBJECT_TO_VLOG(BTComp, this);
        }

        // make sure BrainComponent points at the newly created BT co0mponent
        BrainComponent = BTComp;

        check(BTComp != NULL);
        BTComp->StartTree(*BTAsset, EBTExecutionMode::Looped);
    }
    else {
        UE_LOG(LogTemp, Display, TEXT("Fail"));
    }

    return bSuccess;
}
