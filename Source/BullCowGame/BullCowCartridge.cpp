// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(WordList);
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
    PrintLine(TEXT("%i valid words"), Isograms.Num());
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
    // HiddenWord = ValidWords[0];
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
    FBullCowCount Count = GetBullCows(Input);
    PrintLine(TEXT("You have %i Bulls and %i Cows"), Count.Bulls, Count.Cows);
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
    // for (int32 i = 0; i < Words.Num(); i++)
    // {
    //     if (Words[i].Len() >= 4 && Words[i].Len() <= 8 && IsIsogram(Words[i]))
    //     {
    //         Result.Emplace(Words[i].ToLower());
    //     }
    // }
    for (FString Word : Words)
    {
        Word = Word.ToLower();
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            Result.Emplace(Word);
            // UE_LOG(LogTemp, Warning, TEXT("Adding %s %d"), *Word, IsIsogram(Word));
        } 
    }
    // for (FString Word : Result)
    // {
    //      PrintLine(Word);
    //      UE_LOG(LogTemp, Warning, TEXT("%s"), *Word);
    // }
    return Result;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;
    int32 HisIndex;
    for (int32 i = 0; i < Guess.Len(); i++)
    {
        HiddenWord.FindChar(Guess[i], HisIndex);
        if (HisIndex == i)
        {
            Count.Bulls++;
            continue;
        }
        if (HisIndex >= 0)
        {
            Count.Cows++;
        }
    }
    return Count;
}
