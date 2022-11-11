// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameStruct.h"
#include "StandartHUD.generated.h"

/**
 * 
 */


UCLASS()
class OWLISH_API AStandartHUD : public AHUD
{
	GENERATED_BODY()
	protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	UFont* hudFont;
	virtual void DrawHUD() override;
	void DrawWidgets();
	void  DrawMessages();
	TArray<Widget> widgets;
	TArray<Message> messages;
public:
	void addMessage( Message msg );
	void addWidget( Widget widget );
	void clearWidgets();
};
