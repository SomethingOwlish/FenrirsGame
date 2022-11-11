// Fill out your copyright notice in the Description page of Project Settings.


#include "ZoneNotAloowed.h"

// Sets default values
AZoneNotAloowed::AZoneNotAloowed() 
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AZoneNotAloowed::AZoneNotAloowed(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));
	ProxSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ProxSphere->SetSphereRadius( 150.0f );

	ProxSphere->OnComponentBeginOverlap.AddDynamic( this, &AZoneNotAloowed::Prox );
	ZoneMessage = "Hi";// сообщение по умолчанию, может быть отредактировано
	// в blueprint

};

// Called when the game starts or when spawned
void AZoneNotAloowed::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZoneNotAloowed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AZoneNotAloowed::Prox_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &
SweepResult )
{
	AWolfPlayer * playerPawn = Cast<AWolfPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if( OtherActor != playerPawn)
	{	
		return;
	
	}

	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if( PController )
	{//UE_LOG(LogTemp, Warning, TEXT("Here a good tatment") );
		AStandartHUD * hud = Cast<AStandartHUD>( PController->GetHUD() );
		hud->addMessage(  Message(WhoSays, FString(": ") + ZoneMessage, 5.f, FColor::White, Face) );
	}
}
