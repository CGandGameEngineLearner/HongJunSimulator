// Fill out your copyright notice in the Description page of Project Settings.


#include "ConnectionSystem/ConnectionComponent.h"

#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(ConnectionSystem)

// Sets default values for this component's properties
UConnectionComponent::UConnectionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UConnectionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	TSubclassOf<AActor> ConnectionSystemClass=AConnectionSystem::StaticClass();
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ConnectionSystemClass,OutActors);
	if(OutActors.Num()>0)
	{
		MyConnectionSystem=Cast<AConnectionSystem>(OutActors[0]);
	}
	else
	{
		UE_LOG(ConnectionSystem,Warning,TEXT("游戏场景中未放置ConnectionSystem，无法与ConnectionSystem取得连接"));
	}
}


// Called every frame
void UConnectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	UpdateActorInformation();
}

void UConnectionComponent::ActorDie()
{
	AActor* Owner=GetOwner();
	UE_LOG(ConnectionSystem,Display,TEXT("Actor死亡"));
	FString DeadActorName=Owner->GetName();
	MyConnectionSystem->ActorDieFunction(DeadActorName);
}

void UConnectionComponent::UpdateActorInformation()
{
	AActor* Owner=GetOwner();
	MyConnectionSystem->UploadActorInformation(Owner);
}

