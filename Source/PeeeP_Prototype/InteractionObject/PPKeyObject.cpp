// Fill out your copyright notice in the Description page of Project Settings.

// UGameplayStatics::GetPlayerCharacter 사용 위해 추가
#include "Kismet/GameplayStatics.h"

#include "Character/PPCharacterBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "InteractionObject/PPKeyObject.h"

// Sets default values
APPKeyObject::APPKeyObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

	CollisionBox->SetupAttachment(Body);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APPKeyObject::OnOverlapBegin);

	Key = TEXT("FirstKey");
}

// Called when the game starts or when spawned
void APPKeyObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void APPKeyObject::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("col"));

	APPCharacterBase* Player = Cast<APPCharacterBase>(UGameplayStatics::GetPlayerCharacter(this, 0)); // 플레이어 캐릭터를 직접 불러와서 함수 사용 -> 플레이어 캐릭터 자체에 key값 추가 위함
	if (!Player->CheckKeyCard(Key))  // 키카드를 가지고 있지 않다면
	{
		Player->AddKeyCard(Key);  // 추가
	}

	Destroy(); // 획득하면 삭제
}

// Called every frame
void APPKeyObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}