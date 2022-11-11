// Fill out your copyright notice in the Description page of Project Settings.


#include "WolfPlayer.h"


// Sets default values
AWolfPlayer::AWolfPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	


}

// Called when the game starts or when spawned
void AWolfPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWolfPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWolfPlayer::SetupPlayerInputComponent( UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	check(InputComponent);
	InputComponent->BindAxis("Forward", this, &AWolfPlayer::MoveForward);
//	InputComponent->BindAxis("RightMove", this, &AWolfPlayer::MoveRight);
	InputComponent->BindAxis("Yaw", this, &AWolfPlayer::Yaw);
	InputComponent->BindAxis("Pitch", this, &AWolfPlayer::Pitch);
	InputComponent->BindAction("Bite", IE_Pressed, this, &AWolfPlayer::Bite);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AWolfPlayer::Jump);
	InputComponent->BindAction( "Inventory", IE_Pressed, this, &AWolfPlayer::ToggleInventory );
}

void AWolfPlayer::MoveForward( float amount )
{
	if( Controller && amount )
	{
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}
/*void AWolfPlayer::MoveRight( float amount )
{
	if( Controller && amount )
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}
*/

void AWolfPlayer::Yaw( float amount )
{if( inventoryShowing )
{
	return; 
}
	AddControllerYawInput(MouseSensetive* amount * GetWorld()->GetDeltaSeconds());
}
void AWolfPlayer::Pitch( float amount )
{if( inventoryShowing )
{
	return; 
}
	AddControllerPitchInput(MouseSensetive * amount * GetWorld()->GetDeltaSeconds());
}

void AWolfPlayer::Jump ()
{
	if( Controller )
	{ 
		ACharacter::Jump();
	
	}

}
void AWolfPlayer::Bite()
{
	isBite = true;
	isBiteEnd = false;
	GetWorld()->GetTimerManager().SetTimer(FTimerBite, this, &AWolfPlayer::BiteEnd, 0.7f, false);

	
}
void AWolfPlayer::BiteEnd()
{
	isBite = false;
	isBiteEnd = true;
}


void AWolfPlayer::Pickup( APickupItem *item )
{
	if( Backpack.Find( item->Name ) )
	{
		Backpack[ item->Name ] += item->Quantity;
	}
	else
	{
		Backpack.Add(item->Name, item->Quantity);
		Icons.Add(item->Name, item->Icon);
	}
}

void AWolfPlayer::ToggleInventory()
{
	if( GEngine )
	{
		GEngine->AddOnScreenDebugMessage( 0, 5.f, FColor::Red, "Showinginventory…" );
	}
	// Получаем контроллер и HUD
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	AStandartHUD* hud = Cast<AStandartHUD>( PController->GetHUD() );
	// Если инвентарь отображается, то прекращаем отображать его.
	if( inventoryShowing )
	{
		hud->clearWidgets();
		inventoryShowing = false;
		PController->bShowMouseCursor = false;
		return;
	}
	// Иначе отображаем инвентарь игрока
	inventoryShowing = true;
	PController->bShowMouseCursor = true;
	for( TMap<FString,int>::TIterator it = Backpack.CreateIterator(); it; ++it )
	{
		// Комбинируем имя предмета с количеством, то есть Cow x 5
		FString fs = it->Key + FString::Printf( TEXT(" x %d"), it->Value );
		UTexture2D* tex;
	if( Icons.Find( it->Key ) )
		{
			Icons[it->Key];
			tex = Icons[it->Key];
			hud->addWidget( Widget( Icon( fs, tex ) ) );
		};
	}
}

