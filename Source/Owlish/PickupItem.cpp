// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupItem.h"
#include "StandartHUD.h"
#include "WolfPlayer.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickupItem::APickupItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APickupItem::APickupItem(const class  FObjectInitializer& PCIP) : Super(PCIP)
{
	Name = "UNKNOWN ITEM"; 
	Quantity = 0;
	// Задаём объект Unreal
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));
	Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(true);
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::Prox);
	ProxSphere->AttachToComponent(Mesh, FAttachmentTransformRules::KeepRelativeTransform);
}
	void APickupItem::Prox_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
	{
	AWolfPlayer * playerPawn = Cast<AWolfPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if( OtherActor != playerPawn)
	{	
		return;
	
	}
		AWolfPlayer *avatar = Cast<AWolfPlayer>( UGameplayStatics::GetPlayerPawn( GetWorld(), 0 ) );
		avatar->Pickup( this );
		APlayerController* PController = GetWorld()->GetFirstPlayerController();
		AStandartHUD* hud = Cast<AStandartHUD>( PController->GetHUD() );
		hud->addMessage( Message( Icon, FString("Picked up ") + FString::FromInt(Quantity) +
		FString(" ") + Name, 5.f, FColor::White, FColor::Black ) );
		Destroy();
	}