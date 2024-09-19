// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PEEEP_PROTOTYPE_API APPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	APPPlayerController();

protected:
	virtual void BeginPlay() override;

	// ���� Ŭ������ ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	TSubclassOf<class UPPInGameUIMain> InGameUIMainClass;
	// ���� ������ ������ ����Ű�� ������
	UPROPERTY()
	TObjectPtr<class UPPInGameUIMain> InGameUIMain;

public:

};
