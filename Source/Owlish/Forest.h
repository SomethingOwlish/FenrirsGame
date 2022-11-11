// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Forest.generated.h"

UCLASS()
class OWLISH_API AForest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AForest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
