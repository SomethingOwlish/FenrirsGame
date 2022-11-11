// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PickupItem.h"
#include "CoreMinimal.h"
#include "StandartHUD.h"
#include "GameFramework/Character.h"
#include "HumanCharacter.generated.h"

UCLASS()
class OWLISH_API AHumanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHumanCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
