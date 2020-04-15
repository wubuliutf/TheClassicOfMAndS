// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "ZombieCharacter.h"
#include "MyZombieOne.h"
#include "MainCharacter.h"


// Sets default values
AMyZombieOne::AMyZombieOne()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BlackBoardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

}

// Called when the game starts or when spawned
void AMyZombieOne::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyZombieOne::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyZombieOne::OnPossess(APawn* InPawn)
{
	Super::Possess(InPawn);

	AMyZombieOne* Char = Cast<AMyZombieOne>(InPawn);

	if (Char && Char->BotBehavior)
	{
		BlackBoardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		MonsterKeyID = BlackBoardComp->GetKeyID("target");

		BehaviorComp->StartTree(*Char->BotBehavior);
	}

}


