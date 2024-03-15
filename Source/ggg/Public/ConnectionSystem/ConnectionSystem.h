// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SocketIOClient/Public/SocketIOClientComponent.h"
#include "Json/Public/Json.h"
#include "JsonUtilities/Public/JsonUtilities.h"


#include "ConnectionSystem.generated.h"


UCLASS()
class GGG_API AConnectionSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConnectionSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "My Actor Components")
	USocketIOClientComponent* SocketIOClientComponent;

public:
	//DECLARE_EVENT_OneParam(AConnectionSystem, ActorDieEvent, AActor*);
	
private:
	//ActorDieEvent Actor_Die_Event;
	
public:
	//ActorDieEvent& OnActorDie(){return Actor_Die_Event;}

	UFUNCTION(BlueprintCallable,Category="ConnectionSystem")
	void ActorDieFunction(FString DeadActorName);

	UFUNCTION(BlueprintCallable,Category="ConnectionSystem")
	void UploadActorInformation(AActor* Actor);
	
};
