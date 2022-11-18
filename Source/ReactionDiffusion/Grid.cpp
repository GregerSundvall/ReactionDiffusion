// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

#include "Engine/TextureRenderTarget2D.h"


// Sets default values
AGrid::AGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();
	

	FTransform Transform;

	for (int i = 0; i < Height; ++i)
	{
		TArray<APixel*> Row;
		for (int j = 0; j < Width; ++j)
		{
			Transform.SetLocation(GetActorLocation() + FVector(0, j, -i));
			APixel* Pixel = Cast<APixel>(GetWorld()->SpawnActor(PixelType, &Transform));
			Row.Add(Pixel);
		}
		Pixels.Add(Row);
	}
	
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// UE_LOG(LogTemp, Warning, TEXT("ts %f"), Timestamp);
	// UE_LOG(LogTemp, Warning, TEXT("dt %f"), GetWorld()->TimeSeconds);
	
	if (Timestamp + 1.0f < GetWorld()->TimeSeconds)
	{
		UE_LOG(LogTemp, Warning, TEXT("true"));

		for (int i = 0; i < Height; ++i)
		{
			for (int j = 0; j < Width; ++j)
			{
				Pixels[i][j]->StaticMesh->SetHiddenInGame(!Pixels[i][j]->StaticMesh->bHiddenInGame);
			}
		}
		Timestamp = GetWorld()->TimeSeconds;
	}

	
	

}

