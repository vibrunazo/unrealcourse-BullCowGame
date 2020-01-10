// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    // PrintLine(TEXT("The HiddenWord is: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());
    // PrintLine(FString::Printf(TEXT("The HiddenWord is: %s"), *HiddenWord));
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    // if life == 0,  game over
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        PlayGame(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("macaco");
    Lives = 3;
    bGameOver = false;
    // prompts for a guess
    PrintLine(TEXT("Hi There for instance!"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Hidden word was: %s"), *HiddenWord);
    PrintLine(TEXT("Press ENTER to play again."));
}

void UBullCowCartridge::PlayGame(const FString& Input)
{
if (HiddenWord == Input)
    {
        PrintLine(TEXT("YES"));
        EndGame();
        return;
    }
    PrintLine(TEXT("NO"));
    Lives--;
    if (HiddenWord.Len() != Input.Len())
    {
        PrintLine(TEXT("Hidden word is %i chars long."), HiddenWord.Len());
    }
    FString LivesText = TEXT("Lives left: ");
    LivesText.AppendInt(Lives);
    PrintLine(LivesText);
    // PrintLine(TEXT("Hidden word was: %s"), *HiddenWord);

    // if life == 0, game over
    if (Lives == 0)
    {
        PrintLine(TEXT("GG Motherfucker."));
        EndGame();
    }
}