// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameStruct.generated.h"

UENUM(BlueprintType)
enum class ERelateType : uint8 {
	Lover = 0 UMETA(DisplayName = "Lover"),
	Friend = 1 UMETA(DisplayName = "Friend"),
	Symp = 2 UMETA(DisplayName = "Symp"),
	Neutral = 3 UMETA(DisplayName = "Neutral")
	};
UENUM(BlueprintType)
enum class ECharacterTyper : uint8 {
	Wolf= 0 UMETA(DisplayName = "Wolf"),
	Human = 1 UMETA(DisplayName = "Human"),
	};

struct Icon
{
	FString name;
	UTexture2D* tex;
	Icon(){ name = "UNKNOWN ICON"; tex = 0; }
	Icon( FString& iName, UTexture2D* iTex )
	{
		name = iName;
		tex = iTex;
	}
};
struct Widget
{
	Icon icon;
	FVector2D pos, size;
	Widget(Icon iicon)
	{
		icon = iicon;
	}
	float left(){ return pos.X; }
	float right(){ return pos.X + size.X; }
	float top(){ return pos.Y; }
	float bottom(){ return pos.Y + size.Y; }
	
};

struct Message
{
	FString message;
	FString name;
	float time;
	FColor color;
	UTexture2D* tex;
	Icon icon;
	Message()
	{
		time = 5.f;
		color = FColor::White;
	}
	Message( FString iName, FString iMessage, float iTime, FColor iColor, UTexture2D* iTex)
	{	name = iName;
		message = iMessage;
		time = iTime;
		color = iColor;
		tex = iTex;
	}
	Message (UTexture2D* icon, FString iMessage, float iTime, FColor iColorF, FColor iColorS )
	{
		tex = icon;
		message = iMessage;
		time = iTime;
		color = iColorF;
		
	}
	
};


UCLASS()
class OWLISH_API UGameStruct : public UObject
{
	GENERATED_BODY()
};
