// Fill out your copyright notice in the Description page of Project Settings.


#include "Flash.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include <Developer\MaterialBaking\Public\MaterialBakingHelpers.h>

// Sets default values
AFlash::AFlash()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LightIntensity = 9000.f;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity;
	PointLight->bVisible = true;
	RootComponent = PointLight;

	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Comp"));
	LightSphere->InitSphereRadius(200.0f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetupAttachment(RootComponent);

	LightSphere->OnComponentBeginOverlap.AddDynamic(this, &AFlash::OnOverlapBegin);
	LightSphere->OnComponentEndOverlap.AddDynamic(this, &AFlash::OnOverlapEnd);
}
	
	

// Called when the game starts or when spawned
void AFlash::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

// Called every frame
void AFlash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFlash::ToggleFire()
{
	PointLight->ToggleVisibility();
}

void AFlash::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32
	OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor&&(OtherActor!=this)&&OtherComp)
	{
		ToggleFire();
	}
}

void AFlash::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleFire();
	}
}

void AFlash::Spawn()
{
	if (ToSpawn)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			FRotator rotator;
			FVector spawnLocation = this->GetActorLocation();
			world->SpawnActor<AActor>(ToSpawn, spawnLocation, rotator, spawnParams);
		}
	}
}