// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStruct.h"
#include "GameFramework/Character.h"
#include "WolfPlayer.h"
#include "Components/ActorComponent.h"
#include "WerewolfSwitch.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDiedSignature, ACharacter*, Character);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OWLISH_API UWerewolfSwitch : public UActorComponent
{
	GENERATED_BODY()
	ECharacterTyper Form = ECharacterTyper::Wolf;
public:
	// Sets default values for this component's properties
	UWerewolfSwitch();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
