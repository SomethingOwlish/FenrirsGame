// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameStruct.h"
#include "NPC.generated.h"


UCLASS()
class OWLISH_API ANPC : public ACharacter
{
	GENERATED_BODY()
	protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision)
	class USphereComponent* ProxSphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	FString NpcMessage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	FString NPCName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	UTexture2D* Face;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	ERelateType Relate = ERelateType::Neutral;
	
    UFUNCTION(BlueprintNativeEvent, Category = "Collision")
    void Prox(class UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
    OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult );
	

public:
	// Sets default values for this character's properties
	ANPC();
	ANPC(const class FObjectInitializer& PCIP);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
