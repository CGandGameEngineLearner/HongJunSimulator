// Fill out your copyright notice in the Description page of Project Settings.


#include "ConnectionSystem/ConnectionSystem.h"

#include "ConnectionSystem/ConnectionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Json/Public/Dom/JsonObject.h"
#include "Json/Public/Dom/JsonValue.h"
#include "SIOJson/Public/SIOJLibrary.h"
#include "Math/Color.h"

// Sets default values
AConnectionSystem::AConnectionSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SocketIOClientComponent=CreateDefaultSubobject<USocketIOClientComponent>(TEXT("SocketIOClientComponent"));
	//Actor_Die_Event.AddUFunction(this,FName(TEXT("ActorDieFunction")));
}

// Called when the game starts or when spawned
void AConnectionSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConnectionSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AConnectionSystem::ActorDieFunction(FString DeadActorName)
{
	
	
	UKismetSystemLibrary::PrintString(this,FString(TEXT("有无人机被摧毁")),true,true,FLinearColor(0.0, 0.66, 1.0),2.0f);
	
	/*auto JsonObject = USIOJConvert::MakeJsonObject();
	JsonObject->SetStringField(FString(TEXT("dead_actor_name")),DeadActorName);
	SocketIOClientComponent->EmitNative(TEXT("ActorDie"), JsonObject);
	
	/*
	SocketIOClientComponent->EmitNative(TEXT("ActorDie"), JsonObject, [&](auto Response)
	{
	},FString(TEXT("/")));
	#1#
	UE_LOG(ConnectionSystem,Warning,TEXT("当前调用的ActorDieFunction已经被弃用，无法发送Actor被摧毁的信息"));*/

	USIOJsonObject* JsonObject=USIOJsonObject::ConstructJsonObject(this);
	JsonObject->SetStringField(FString(TEXT("dead_actor_name")),DeadActorName);
	USIOJsonValue* JsonValue= USIOJLibrary::Conv_JsonObjectToJsonValue(JsonObject);
	this->SocketIOClientComponent->Emit(TEXT("ActorDie"),JsonValue,FString(TEXT("/")));
}

void AConnectionSystem::UploadActorInformation(AActor* Actor)
{
	USIOJsonObject* JsonObject=USIOJsonObject::ConstructJsonObject(this);
	FVector ActorLocation=Actor->GetActorLocation();
	FRotator ActorRotator=Actor->GetActorRotation();
	FVector ActorScale=Actor->GetActorScale();
	FString DeadActorName=Actor->GetName();
	JsonObject->SetStringField(FString(TEXT("actor_name")),DeadActorName);
	JsonObject->SetNumberField(FString(TEXT("x")),ActorLocation.X);
	JsonObject->SetNumberField(FString(TEXT("y")),ActorLocation.Y);
	JsonObject->SetNumberField(FString(TEXT("z")),ActorLocation.Z);
	JsonObject->SetNumberField(FString(TEXT("pitch")),ActorRotator.Pitch);
	JsonObject->SetNumberField(FString(TEXT("yaw")),ActorRotator.Yaw);
	JsonObject->SetNumberField(FString(TEXT("roll")),ActorRotator.Roll);
	JsonObject->SetNumberField(FString(TEXT("scale_x")),ActorScale.X);
	JsonObject->SetNumberField(FString(TEXT("scale_y")),ActorScale.Y);
	JsonObject->SetNumberField(FString(TEXT("scale_z")),ActorScale.Z);
	TArray<FString> TagStrings;
	for(auto Tag : Actor->Tags)
	{
		TagStrings.Add(Tag.ToString());
	}
	JsonObject->SetStringArrayField(FString(TEXT("scale_z")),TagStrings);
	USIOJsonValue* JsonValue= USIOJLibrary::Conv_JsonObjectToJsonValue(JsonObject);
	this->SocketIOClientComponent->Emit(TEXT("UpdateActorInformation"),JsonValue,FString(TEXT("/")));
	
}

