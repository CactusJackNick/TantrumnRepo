// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TantrumnPlayerController.generated.h"

class ATantrumGameModeBase;

UCLASS()
class TANTRUMN_API ATantrumnPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetupInputComponent() override;

	void RequestMoveForward(float AxisValue);
	void RequestMoveRight(float AxisValue);
	void RequestLookUp(float AxisValue);
	void RequestLookRight(float AxisValue);
	void RequestThrowObject(float AxisValue);

	void RequestPullObject();
	void RequestStopPullObject();

	void RequestJump();
	void RequestCrouch();
	void RequestSprintStart();
	void RequestSprintEnd();

	// Base lookup rate, in deg/sec. Other scaling may affect final lookup rate.
	UPROPERTY(EditAnywhere, Category = "Look")
	float BaseLookUpRate = 90.0f;

	// Base lookup rate, in deg/sec. Other scaling may affect final lookup rate.
	UPROPERTY(EditAnywhere, Category = "Look")
	float BaseLookRightRate = 90.0f;

	//used to determine flick of axis
	//float LastDelta = 0.0f;
	float LastAxis = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Input")
	float FlickThreshold = 0.75f;

protected:
	float RunSpeed = 600.f;
	float SprintSpeed = 1200.f;
};
