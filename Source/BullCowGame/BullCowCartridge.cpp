// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the six letter word!"));
    PrintLine(TEXT("Press ENTER to continue!!"));
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("cheese");
    if (Input == HiddenWord)
    {

        PrintLine(TEXT("You got it right! You win!"));
    }
    else
    {
        PrintLine(TEXT("You got it incorrect! You lose"));
    }
}