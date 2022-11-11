// Fill out your copyright notice in the Description page of Project Settings.


#include "StandartHUD.h"
#include "Engine/Canvas.h"

void AStandartHUD::DrawHUD()
{
	
	Super::DrawHUD();
	
	DrawMessages();
	DrawWidgets();
	
}



void AStandartHUD::addMessage( Message msg )
{
	messages.Add( msg );
}

void AStandartHUD::DrawWidgets()
{
	for( int c = 0; c < widgets.Num(); c++ )
	{
		DrawTexture( widgets[c].icon.tex, widgets[c].pos.X, widgets[c].pos.Y, widgets[c].size.X,
		widgets[c].size.Y, 0, 0, 1, 1 );
		DrawText( widgets[c].icon.name, FLinearColor::Yellow, widgets[c].pos.X, widgets[c].pos.Y,
		hudFont, .6f, false );
	}
}
void AStandartHUD::addWidget( Widget widget )
{
	// находим положение графического элемента, расположенного в сетке.
	// изображаем значки...
	FVector2D start( 200, 200 ), pad( 12, 12 );
	widget.size = FVector2D( 100, 100 );
	widget.pos = start;
	// вычисляем положение здесь
	for( int c = 0; c < widgets.Num(); c++ )
	{
		// Немного смещаем положение вправо.
		widget.pos.X += widget.size.X + pad.X;
		float SizeY = Canvas->SizeY;
		if( widget.pos.X + widget.size.X > SizeY )
		{
			widget.pos.X = start.X;
			widget.pos.Y += widget.size.Y + pad.Y;
		}
	}
	widgets.Add( widget );
}

void AStandartHUD::DrawMessages()
{
	for( int c = messages.Num() - 1; c >= 0; c-- )
	{
		// изображаем фоновое окно для сообщения
		// нужного размера
		float outputMWidth, outputNWidth, outputMHeight, outputNHeight, pad=10.f;
		GetTextSize( messages[c].message, outputMWidth, outputMHeight, hudFont, 3.f );
		GetTextSize( messages[c].name, outputNWidth, outputNHeight, hudFont, 3.f );
		float messageH = outputMHeight + outputNHeight + 2.f*pad;
		float x = outputNWidth+outputMHeight+pad, y = c*messageH;
		DrawRect( FLinearColor::Black, x, y, Canvas->SizeX, messageH );
		DrawTexture( messages[c].tex, x, y, messageH, messageH, 0, 0, 1, 1 );
		DrawText( messages[c].name, FColor::Green, x + pad + messageH, y + pad, hudFont,3.0f );
		DrawText( messages[c].message, messages[c].color, (x + pad + messageH + outputNWidth), y + pad + 10.f, hudFont,2.0f );
		// сокращаем время отображения на время прошедшее
		// с последнего кадра.
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		// если время сообщения вышло, удаляем его
		if( messages[c].time < 0 )
		{
			messages.RemoveAt( c );
		}
	}
}
void AStandartHUD::clearWidgets()
{for( int c = widgets.Num() - 1; c >= 0; c-- )
{
	widgets.RemoveAt( c );
}
}