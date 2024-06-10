// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"

#include "Turret.generated.h"


UCLASS()
class GGG_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Turret")
		float Running_Speed_Multiplier;

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Radar")
		float Max_Search_Range=6000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Radar")
		FName Enemy_Tag=FName(TEXT("AI_Drone0"));
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
		float Max_Range=5000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
		float Min_Range=200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
		float Min_Pitch=-10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
		float Max_Pitch=90.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
		float Min_Yaw=-180.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar")
		float Max_Yaw=180.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar",meta=(Tooltip="忽略带有该标签的敌人"))
		FName	Ignore_Tag=FName(TEXT("Dead"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radar",meta=(Tooltip="雷达锁定目标"))
		AActor* Radar_Lockon_Target=nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Radar")
		TEnumAsByte<EDrawDebugTrace::Type> Draw_Debug_Type;
	
public:

	/*准备以后把炮塔蓝图中的Search函数的用这个C++函数代替*/
	UFUNCTION(BlueprintCallable, Category = "Turret|Radar")
		void SearchEnemy();
	
private:
		bool CheckCanAttack(TWeakObjectPtr<AActor> TargetActor);
};
