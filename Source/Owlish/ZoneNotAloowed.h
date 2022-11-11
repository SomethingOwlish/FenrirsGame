// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WolfPlayer.h"
#include "Components/SphereComponent.h"
#include "ZoneNotAloowed.generated.h"

UCLASS()
class OWLISH_API AZoneNotAloowed : public AActor
{
	GENERATED_BODY()
		protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ZoneParametrs)
	bool IsActive;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ZoneMessage)
    	FString ZoneMessage;
    	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ZoneMessage)
        	FString WhoSays;
        	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ZoneMessage)
        	UTexture2D* Face;
    	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision)
        	class USphereComponent* ProxSphere;
        	
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
void Prox(class UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult );
	
public:	

	// Sets default values for this actor's properties
	AZoneNotAloowed();
	AZoneNotAloowed(const class FObjectInitializer& PCIP);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
