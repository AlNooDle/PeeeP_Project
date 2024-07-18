// Fill out your copyright notice in the Description page of Project Settings.


#include "PPCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PPCharacterControlData.h"

// Sets default values
APPCharacterBase::APPCharacterBase()
{
	// Pawn
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Capsule
	GetCapsuleComponent()->InitCapsuleSize(23.f, 20.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// Movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Mesh
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -25.0f), FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetRelativeScale3D(FVector(1.75f, 1.75f, 1.75f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetCollisionProfileName(TEXT("NoCollision"));

	// 메쉬 지정
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/PeePCharacter/rig.rig'"));
	if (CharacterMeshRef.Object)
	{
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
	}

	// 애니메이션 지정
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassRef(TEXT("/Game/Characters/PeePCharacter/Animation/ABP_Peep.ABP_Peep_C"));
	if (AnimInstanceClassRef.Class)
	{
		GetMesh()->SetAnimInstanceClass(AnimInstanceClassRef.Class);
	}

	static ConstructorHelpers::FObjectFinder<UPPCharacterControlData> ShoulderDataRef(TEXT("/Script/PeeeP_Prototype.PPCharacterControlData'/Game/CharacterControl/PPC_Move.PPC_Move'"));
	if (ShoulderDataRef.Object)
	{
		CharacterControlManager.Add(ECharacterControlType::Shoulder, ShoulderDataRef.Object);
	}
}

void APPCharacterBase::SetCharacterControlData(const UPPCharacterControlData* CharacterControlData)
{
	// Pawn
	bUseControllerRotationYaw = CharacterControlData->bUseControllerRotationYaw;

	// CharacterMovement
	GetCharacterMovement()->bOrientRotationToMovement = CharacterControlData->bOrientRotationToMovement;
	GetCharacterMovement()->bUseControllerDesiredRotation = CharacterControlData->bUseControllerDesiredRotation;
	GetCharacterMovement()->RotationRate = CharacterControlData->RotationRate;
}



void APPCharacterBase::AddKeyCard(FName keyName)  // 아이템 추가
{
	if (!KeyCards.Contains(keyName))
	{
		KeyCards.Add(keyName, true);
	}
	UE_LOG(LogTemp, Log, TEXT("get"));

	if (KeyCards.Contains(keyName))
	{
		bool Value = KeyCards[keyName];
		UE_LOG(LogTemp, Warning, TEXT("Key: %s, Value: %d"), *keyName.ToString(), Value ? 1 : 0);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Key not found in KeyCards map: %s"), *keyName.ToString());
	}

}

bool APPCharacterBase::CheckKeyCard(FName keyName)  // 아이템 유무 확인
{
	if (KeyCards.Contains(keyName))
	{
		return true;
	}

	return false;
}