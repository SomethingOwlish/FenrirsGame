// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"
#include "WolfPlayer.h"
#include "StandartHUD.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"

// Sets default values

ANPC::ANPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

ANPC::ANPC(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));
	ProxSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ProxSphere->SetSphereRadius( 150.0f );

	ProxSphere->OnComponentBeginOverlap.AddDynamic( this, &ANPC::Prox );
	NpcMessage = "Hi";// сообщение по умолчанию, может быть отредактировано
	// в blueprint
}

void ANPC::Prox_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &
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
		hud->addMessage(  Message(NPCName, FString(": ") + NpcMessage, 5.f, FColor::White, Face) );
	}
}
