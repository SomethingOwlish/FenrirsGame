// Fill out your copyright notice in the Description page of Project Settings.


#include "WerewolfSwitch.h"

#include "HumanCharacter.h"


// Sets default values for this component's properties
UWerewolfSwitch::UWerewolfSwitch()
{
	if (Form == ECharacterTyper::Wolf){
		 Form = ECharacterTyper::Human;
		
	} else if (Form == ECharacterTyper::Human)
	{
		 Form = ECharacterTyper::Wolf;
		//GetWorld()->GetFirstPlayerController()->Possess(AHumanCharacter);
	}
	else
	{
		return;
	};
}


// Called when the game starts
void UWerewolfSwitch::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWerewolfSwitch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

