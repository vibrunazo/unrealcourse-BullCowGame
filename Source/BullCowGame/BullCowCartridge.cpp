// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hi There for instance!"));
    PrintLine(TEXT("Input something."));
    HiddenWord = TEXT("bunda");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    PrintLine(TEXT("Cleared."));
    FString GuessWord = Input;
    if (HiddenWord == Input)
    {
        PrintLine(TEXT("YES"));
    }
    else
    {
        PrintLine(TEXT("NO"));
    }
    
    PrintLine(TEXT("Hidden word was:"));
    PrintLine(HiddenWord);
}