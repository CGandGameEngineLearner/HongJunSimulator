// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Missile.h"
#include "MissileSystem.generated.h"



UCLASS()
class GGG_API AMissileSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMissileSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category = "MissileSystem")
		TArray<AMissile*> missiles_;

	UFUNCTION(BlueprintNativeEvent, Category = "MissileSystem")
		void attack(AActor* target_actor);

	UFUNCTION(BlueprintNativeEvent, Category = "MissileSystem")
		void searchEnemy();
};
