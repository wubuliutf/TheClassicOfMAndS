// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SpotlightComponent.h"
#include "Flash.generated.h"

UCLASS()
class THECLASSICOFMANDS_API AFlash : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlash();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor>ToSpawn;

	UFUNCTION(BlueprintCallable)
		void Spawn();

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class USphereComponent* LightSphere;

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		float LightIntensity;

	UFUNCTION()
		void ToggleFire();
	

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 
			OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
		
};
