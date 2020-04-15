// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZombieCharacter.generated.h"

UCLASS()
class THECLASSICOFMANDS_API AZombieCharacter : public AActor
{
	GENERATED_BODY()


	
public:	
	// Sets default values for this actor's properties
	AZombieCharacter();
	UPROPERTY(EditAnywhere, category = Behavior)

		class UBehaviorTree* BotBehavior;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
