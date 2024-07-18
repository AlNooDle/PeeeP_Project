// Fill out your copyright notice in the Description page of Project Settings.

// UGameplayStatics::GetPlayerCharacter 사용 위해 추가
#include "Kismet/GameplayStatics.h"

#include "Character/PPCharacterBase.h"
#include "InteractionObject/PPKeyCheckObject.h"

// Sets default values
APPKeyCheckObject::APPKeyCheckObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
}

// Called when the game starts or when spawned
void APPKeyCheckObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APPKeyCheckObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APPKeyCheckObject::Execute()
{
	APPCharacterBase* Player = Cast<APPCharacterBase>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Player->CheckKeyCard(KeyName))
	{
		LDoor->SwitchOn();
		RDoor->SwitchOn();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("You don't have key!"));
	}
}

