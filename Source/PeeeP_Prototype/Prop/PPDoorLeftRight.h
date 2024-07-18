// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PPDoorLeftRight.generated.h"

UCLASS()
class PEEEP_PROTOTYPE_API APPDoorLeftRight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APPDoorLeftRight();
	void SwitchOn();
	void MoveDoor(bool IsLeft);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<class UStaticMeshComponent> Body;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool Trigger;
	bool Switch;
	float DoorSpeed;
	double X_Loc;

	UPROPERTY(EditAnywhere, Category = "Value")
	float Value;

	UPROPERTY(EditAnywhere, Category = "DoorDirection")   // 왠지 모르겠는데 Value값으로 음수를 넣으면 작동을 하지 않아 추가했습니다.
	bool IsLeft;
};
