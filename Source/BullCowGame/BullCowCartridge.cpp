// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hi There for instance!"));

    SetupGame();

    // PrintLine(TEXT("The HiddenWord is: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());
    // PrintLine(FString::Printf(TEXT("The HiddenWord is: %s"), *HiddenWord));
    // prompts for a guess
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    // if life == 0,  game over
    if (Lives == 0)
    {
        PrintLine(TEXT("No lives left."));
        return;
    }

    if (HiddenWord == Input)
    {
        PrintLine(TEXT("YES"));
    }
    else
    {
        PrintLine(TEXT("NO"));
        Lives--;
        if (HiddenWord.Len() != Input.Len())
        {
            PrintLine(TEXT("Hidden word is %i chars long."), HiddenWord.Len());
        }
    }
    FString LivesText = TEXT("Lives left: ");
    LivesText.AppendInt(Lives);
    PrintLine(LivesText);
    PrintLine(TEXT("Hidden word was: %s"), *HiddenWord);

    // if life == 0, game over
    if (Lives == 0)
    {
        PrintLine(TEXT("GG Motherfucker."));
    }
    // prompt to play again
    // if yes, call begin play
    // else, quit terminal
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("macaco");
    Lives = 3;
}