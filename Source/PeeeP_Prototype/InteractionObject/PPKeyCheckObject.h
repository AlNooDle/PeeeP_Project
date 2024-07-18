// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/PPButtonExecuteInterface.h"
#include "Prop/PPDoorLeftRight.h"
#include "PPKeyCheckObject.generated.h"

UCLASS()
class PEEEP_PROTOTYPE_API APPKeyCheckObject : public AActor, public IPPButtonExecuteInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APPKeyCheckObject();
	void Execute() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<class UStaticMeshComponent> Body;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Key")
	FName KeyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LDoor")
	APPDoorLeftRight* LDoor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RDoor")
	APPDoorLeftRight* RDoor;
};
