// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pixel.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

UCLASS()
class REACTIONDIFFUSION_API AGrid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGrid();

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Width = 1920;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Height = 1080;
	
	// UPROPERTY()
	TArray<TArray<APixel*>> Pixels;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<APixel> PixelType;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float Timestamp = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
