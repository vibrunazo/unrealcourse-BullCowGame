// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hi There for instance!"));
    PrintLine(TEXT("Input something."));

    InitGame();

    // prompts for a guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    // if life == 0, game over
    if (Lives == 0) 
    {
        PrintLine(TEXT("No lives left."));
        return;
    }
    FString GuessWord = Input;
    if (HiddenWord == Input)
    { 
        PrintLine(TEXT("YES"));
    }
    else
    {
        PrintLine(TEXT("NO"));
        Lives--;
    }
    FString LivesText = TEXT("Lives left: ");
    LivesText.AppendInt(Lives);
    PrintLine(LivesText);
    PrintLine(TEXT("Hidden word was:"));
    PrintLine(HiddenWord);

    // if life == 0, game over
    if (Lives == 0) 
    {
        PrintLine(TEXT("GG Motherfucker."));
    }
    // prompt to play again
    // if yes, call begin play
    // else, quit terminal
}

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("bunda");
    Lives = 3;
}