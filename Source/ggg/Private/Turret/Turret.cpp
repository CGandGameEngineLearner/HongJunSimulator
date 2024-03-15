// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret/Turret.h"


#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ATurret::ATurret()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ATurret::CheckCanAttack(const TWeakObjectPtr<AActor> TargetActor)
{
	if(!(TargetActor->Tags.Find(Enemy_Tag)!=-1&&TargetActor->Tags.Find(Ignore_Tag)==-1))
	{
		return false;
	}
	const float DistanceToTarget =GetDistanceTo(TargetActor.Get());
	if(DistanceToTarget>Max_Range||DistanceToTarget<Min_Range)
	{
		return false;
	}
	FVector UPVector=FVector(0,0,1);
	const FRotator ActorRotation=GetActorRotation();
	UPVector=ActorRotation.RotateVector(UPVector);
	const FVector TargetVector=TargetActor->GetActorLocation()-this->GetActorLocation();
	float DotProduct=FVector::DotProduct(UPVector,TargetVector);
	float AB=UPVector.Size()*TargetVector.Size();
	float CosAB=DotProduct/AB;
	float Rad=FMath::Acos(CosAB);
	
	float Deg=FMath::RadiansToDegrees(Rad);
	Deg=90.f-Deg;
	if(Deg<Min_Pitch||Deg>Max_Pitch)
	{
		return false;
	}
	const FVector ForwardVector=GetActorForwardVector();
	DotProduct=FVector::DotProduct(ForwardVector,TargetVector);
	AB=ForwardVector.Size()*TargetVector.Size();
	CosAB=DotProduct/AB;
	Rad=FMath::Acos(CosAB);
	Deg=FMath::RadiansToDegrees(Rad);
	if(Deg<Min_Yaw||Deg>Max_Yaw)
	{
		return false;
	}
	return true;
}



void ATurret::SearchEnemy()
{
	if(Radar_Lockon_Target&&CheckCanAttack(Radar_Lockon_Target))
	{
		return;
	}
	Radar_Lockon_Target=nullptr;
	//GEngine->AddOnScreenDebugMessage(-1,4.0f,FColor::Blue,TEXT("检测敌人"));
	FVector MyLocation = GetActorLocation();
	//TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	//ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery3);
	TArray<AActor*> IgnoreActors;
	TArray<FHitResult> HitResults;
	bool bHaveEnemy=false;
	bHaveEnemy = UKismetSystemLibrary::SphereTraceMulti(
		this,
		MyLocation,
		MyLocation,
		Max_Search_Range,
		ETraceTypeQuery::TraceTypeQuery3,
		false,
		IgnoreActors,
		Draw_Debug_Type,
		HitResults,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		5.0f
	);
	auto Num=HitResults.Num();
	//UE_LOG(LogTemp,Display,TEXT("Num=%d"),Num);
	if(bHaveEnemy)
	{
		//GEngine->AddOnScreenDebugMessage(-1,4.0f,FColor::Blue,TEXT("检测到了敌人"));
		for (auto HitResult : HitResults)
		{
			auto TargetActor=HitResult.Actor;
			//GEngine->AddOnScreenDebugMessage(-1,4.0f,FColor::Blue,TargetActor->GetName());
			if(TargetActor.IsValid())
			{
				if(CheckCanAttack(TargetActor))
				{
					Radar_Lockon_Target=TargetActor.Get();
					//GEngine->AddOnScreenDebugMessage(-1,4.0f,FColor::Blue,Radar_Lockon_Target->GetName());
					break;
				}
			}
		}
	}
}
