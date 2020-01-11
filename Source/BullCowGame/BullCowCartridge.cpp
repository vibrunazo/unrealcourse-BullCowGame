// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

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
    const TArray<FString> ValidWords = GetValidWords(WordList);
    PrintLine(TEXT("%i valid words"), ValidWords.Num());
    HiddenWord = ValidWords[27];
    Lives = HiddenWord.Len();
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
    if (HiddenWord.Len() != Input.Len())
    {
        PrintLine(TEXT("Hidden word is %i chars long."), HiddenWord.Len());
    }
    if (!IsIsogram(Input))
    {
        PrintLine(TEXT("Not an isogram."));
    }
    PrintLine(TEXT("Lives left: %i"), --Lives);
    // PrintLine(TEXT("Hidden word was: %s"), *HiddenWord);

    // if life == 0, game over
    if (Lives == 0)
    {
        PrintLine(TEXT("GG Motherfucker."));
        EndGame();
    }
}

bool UBullCowCartridge::IsIsogram(const FString& Input) const
{
    for (int32 i = 0; i < Input.Len() - 1; i++)
    {
        for (int32 j = i + 1; j < Input.Len(); j++)
        {
            if (Input[i] == Input[j])
            {
                return false;
            }
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& Words) const
{
    // PrintLine(TEXT("%i possible words"), WordList.Num() );
    TArray<FString> Result;
    for (int32 i = 0; i < Words.Num(); i++)
    {
        if (Words[i].Len() >= 4 && Words[i].Len() <= 8 && IsIsogram(Words[i]))
        {
            Result.Emplace(WordList[i].ToLower());
        }
    }
    // for (int32 i = 0; i < ValidWords.Num(); i++)
    // {
    //      PrintLine(ValidWords[i]);
    // }
    return Result;
}
