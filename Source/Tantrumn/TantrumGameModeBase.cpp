// Fill out your copyright notice in the Description page of Project Settings.

#include "TantrumGameModeBase.h"
#include "Kismet/GameplayStatics.h"

ATantrumGameModeBase::ATantrumGameModeBase()
{

}
void ATantrumGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentGameState = EGameState::Waiting;
	DisplayCountdown();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATantrumGameModeBase::StartGame, GameCountdownDuration, false);
	//StartGame();
}

EGameState ATantrumGameModeBase::GetCurrentGameState() const
{
	return CurrentGameState;
}

void ATantrumGameModeBase::PlayerReachedEnd()
{
	CurrentGameState = EGameState::GameOver;
	
	GameWidget->LevelComplete();
	FInputModeUIOnly InputMode;
	PC->SetInputMode(InputMode);
	PC->SetShowMouseCursor(true);
}

void ATantrumGameModeBase::DisplayCountdown()
{
	if (!GameWidgetClass) { return; }

	PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	GameWidget = CreateWidget<UTantrumnGameWidget>(PC, GameWidgetClass);
	GameWidget->AddToViewport();
	GameWidget->StartCountdown(GameCountdownDuration, this);
}

void ATantrumGameModeBase::StartGame()
{
	CurrentGameState = EGameState::Playing;
	FInputModeGameOnly InputMode;
	PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PC->SetInputMode(InputMode);
	PC->SetShowMouseCursor(false);

}

