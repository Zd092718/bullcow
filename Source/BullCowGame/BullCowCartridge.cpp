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
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You got it right! You win!"));
            EndGame();
        }
        else if (Lives > 0)
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The hidden word is %i characters long. Try again"), HiddenWord.Len());
            }
            --Lives; // decreases lives per missed guess
            PrintLine(TEXT("You got it incorrect! Try again"));
            PrintLine(TEXT("You have %i lives left."), Lives);
        }
        else
        {

            PrintLine(TEXT("You are out of lives! You lose")); // prints when player is out of lives
            EndGame();
        }
    }
}

// Starts Game
void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("hello");
    Lives = 4;
    bGameOver = false;
    PrintLine(TEXT("The hidden word is: %s"), *HiddenWord);

    PrintLine(FString::Printf(TEXT("The hidden word is: %s"), *HiddenWord)); // Debug Line

    // Welcome Player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess! \nPress ENTER to continue..."));
}

// Ends game
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again!"));
}
