// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PickupItem.h"
#include "CoreMinimal.h"
#include "StandartHUD.h"
#include "GameFramework/Character.h"
#include "WolfPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;

	
UCLASS()
class OWLISH_API AWolfPlayer : public ACharacter
{
	GENERATED_BODY()
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	void MoveForward( float amount );
//	void MoveRight( float amount );
	void Yaw( float amount );
	void Pitch( float amount );
	void Jump ();
	void Bite();
	void BiteEnd();
	float MouseSensetive = 200.0f;
	TMap<FString, int> Backpack;
	TMap<FString, UTexture2D*> Icons;
	bool inventoryShowing;
	void ToggleInventory();
protected:
	FTimerHandle FTimerBite;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Status")
	bool isBite = false;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Status")
	bool isBiteEnd = false;
public:
	// Sets default values for this character's properties
	AWolfPlayer();
	void Pickup( APickupItem *item );
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
