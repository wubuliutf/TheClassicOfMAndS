// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "Engine.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*player baisc stats
	*/
	MaxHealth = 100.f;
	Health = 70.f;
	MaxStamina = 100.f;
	Stamina = 90.f;


	WalkingSpeed = 150.f;
	RunningSpeed = 500.f;

	

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer = DeltaTime;

	float DeltaStaminaRecover = StaminaRecoverRate * DeltaTime;

	if (Stamina + DeltaStaminaRecover >= MaxStamina)
	{
		Stamina = MaxStamina;
	}
	else
	{
		Stamina += DeltaStaminaRecover;
	}



}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainCharacter::DecrementStamina(float Amount)
{
	if (Stamina - Amount == 0.f)
	{
		Stamina -= Amount;
		Stamina == 0.f;
	}
}

void AMainCharacter::DecrementHealth(float Amount)
{
	if (Health - Amount == 0.f)
	{
		Health -= Amount;
		Die();
	}
	else
	{
		Health -= Amount;
	}
}

void AMainCharacter::Die()
{
	
}

