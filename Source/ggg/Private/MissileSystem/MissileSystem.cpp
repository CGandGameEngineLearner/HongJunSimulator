// Fill out your copyright notice in the Description page of Project Settings.


#include "MissileSystem/MissileSystem.h"

// Sets default values
AMissileSystem::AMissileSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMissileSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMissileSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMissileSystem::attack_Implementation(AActor* target_actor)
{
	
}

void AMissileSystem::searchEnemy_Implementation()
{

}
