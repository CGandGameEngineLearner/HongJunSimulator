// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConnectionSystem/ConnectionSystem.h"
DECLARE_LOG_CATEGORY_EXTERN(ConnectionSystem, Log, All);

#include "ConnectionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GGG_API UConnectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UConnectionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	FTimerHandle TimerHandle;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginDestroy() override;
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		AConnectionSystem* MyConnectionSystem;
	
public:
	UFUNCTION(BlueprintCallable,Category="ConnectionSystem")
		void ActorDie();

	UFUNCTION(BlueprintCallable,Category="ConnectionSystem")
		void UpdateActorInformation();
	
};
