// Fill out your copyright notice in the Description page of Project Settings.


#include "Prop/PPDoorLeftRight.h"

// Sets default values
APPDoorLeftRight::APPDoorLeftRight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Trigger = false;
	Switch = false;
	DoorSpeed = 3.0f;
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
}

// Called when the game starts or when spawned
void APPDoorLeftRight::BeginPlay()
{
	Super::BeginPlay();
	X_Loc = GetActorLocation().X;
	
}

void APPDoorLeftRight::SwitchOn()
{
	Switch = true;
	if (!Trigger)
	{
		Trigger = true;
	}
}

void APPDoorLeftRight::MoveDoor(bool Direction)
{
	if (Trigger == true)
	{
		if (GetActorLocation().X >= X_Loc + Value || GetActorLocation().X <= X_Loc - Value) { return; }

		if (Direction)
		{
			SetActorLocation(FVector(GetActorLocation().X - DoorSpeed, GetActorLocation().Y, GetActorLocation().Z));
		}
		else
		{
			SetActorLocation(FVector(GetActorLocation().X + DoorSpeed, GetActorLocation().Y, GetActorLocation().Z));
		}
	}
}

// Called every frame
void APPDoorLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Switch)
	{
		if (Trigger)
		{
			MoveDoor(IsLeft);
		}
	}

}

