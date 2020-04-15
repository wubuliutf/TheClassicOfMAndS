// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyZombieOne.generated.h"

UCLASS()
class THECLASSICOFMANDS_API AMyZombieOne : public AActor
{
	GENERATED_BODY()

		UPROPERTY(transient)
		class UBlackboardComponent* BlackBoardComp;
	UPROPERTY(transient)
		class UBehaviorTreeComponent* BehaviorComp;


	UPROPERTY(EditAnywhere)
		float Damage;

	UPROPERTY(EditAnywhere)
		float Distance;

	UPROPERTY(EditAnywhere)
		UParticleSystem* Particle;

	UPROPERTY(EditAnywhere)
		class USoundCue* Sound;
	
public:	
	// Sets default values for this actor's properties
	AMyZombieOne();


	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
		void Attack();

	uint8 MonsterKeyID;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
