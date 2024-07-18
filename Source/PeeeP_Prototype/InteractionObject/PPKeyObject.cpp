// Fill out your copyright notice in the Description page of Project Settings.

// UGameplayStatics::GetPlayerCharacter ��� ���� �߰�
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

	APPCharacterBase* Player = Cast<APPCharacterBase>(UGameplayStatics::GetPlayerCharacter(this, 0)); // �÷��̾� ĳ���͸� ���� �ҷ��ͼ� �Լ� ��� -> �÷��̾� ĳ���� ��ü�� key�� �߰� ����
	if (!Player->CheckKeyCard(Key))  // Űī�带 ������ ���� �ʴٸ�
	{
		Player->AddKeyCard(Key);  // �߰�
	}

	Destroy(); // ȹ���ϸ� ����
}

// Called every frame
void APPKeyObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}