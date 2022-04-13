// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame(); // setting up game
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        InitGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

// Starts Game
void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("hello");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("The hidden word is: %s"), *HiddenWord);

    PrintLine(FString::Printf(TEXT("The hidden word is: %s"), *HiddenWord)); // Debug Line

    // Welcome Player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i attempts!"), Lives);
    PrintLine(TEXT("Type in your guess! \nPress ENTER to continue..."));
}

// Ends game
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again!"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You got it right! You win!"));
        EndGame();
        return;
    }
    else
    {
        --Lives; // decreases lives per missed guess
        if (Lives > 0)
        {
            if (Guess.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The hidden word is %i characters long. Try again"), HiddenWord.Len());
            }
            PrintLine(TEXT("Incorrect! Try again"));
            PrintLine(TEXT("You have %i lives left."), Lives);
        }
        else
        {
            PrintLine(TEXT("You are out of lives! You lose")); // prints when player is out of lives
            EndGame();
        }
    }
}