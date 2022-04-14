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
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("The hidden word is: %s"), *HiddenWord);

    // Welcome Player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i attempts!"), Lives);
    PrintLine(TEXT("Type in your guess! \nPress ENTER to continue..."));

    // const TCHAR HW[] = TEXT("plums");
    // // const TCHAR HW[] = {TEXT('c'), TEXT('a'), TEXT('k'), TEXT('e'), TEXT('s'), TEXT('\0')};
    // PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]);
    // PrintLine(TEXT("The 4th character of HW is: %c"), HW[3]);
}

// Ends game
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again!"));
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    return true;
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You got it right! You win!"));
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i characters long. Try again"), HiddenWord.Len());
        PrintLine(TEXT("You have %i lives left."), Lives);
        return;
    }

    // Checks if guess is isogram
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

    PrintLine(TEXT("Lost a life"));
    --Lives;

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You are out of lives! You lose")); // prints when player is out of lives
        PrintLine(TEXT("Hidden word was %s"), *HiddenWord);

        EndGame();
        return;
    }

    // show player bulls and cows
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}