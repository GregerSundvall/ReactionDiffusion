// Fill out your copyright notice in the Description page of Project Settings.


#include "Pixel.h"


// Sets default values
APixel::APixel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;

	StaticMesh->AddLocalRotation(FRotator(90, 0, 0));
	
}

// Called when the game starts or when spawned
void APixel::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh->SetStaticMesh(Mesh);
	
}

// Called every frame
void APixel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

