/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class. 
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
FText SortGuess();

FBullCowGame BCGame; //Instantiate a new game

int main()
{
	std::cout << BCGame.GetCurrentTry();

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	FBullCowCount BullCowCount;
	//FIsIsogram IsValidIsogram;

	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText Guess = GetValidGuess();

		//FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		//print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl << std::endl;
		//std::cout << BCGame.SortGuess(Guess) << std::endl << std::endl;
		//std::cout << IsValidIsogram.SortedGuess << std::endl;
	}

	//TODO Summarise Game

	return;
}

void PrintIntro() {

	std::cout << "Welcome to Bulls and Cows, a mediocore word game. \n";
	std::cout << "Can you guess the " << BCGame.GetIsogramLength() << " letter isogram I'm thinking off? \n \n";
	return;
}

//Loop continously until there is a valid guess
FText GetValidGuess() //TODO Change to get valid guess
{
	int32 cTry = BCGame.GetCurrentTry();
	std::cout << "Try " << cTry << ". Enter your guess, biiiiiiiiiiiiiiitc-: ";

	FText Guess = "";
	std::getline(std::cin, Guess);

	EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

	//submit valid guess to the game
	switch (Status)
	{
	case EGuessStatus::Wrong_Length:
		std::cout << "Please enter a " << BCGame.GetIsogramLength() << " letter word \n";
		break;

	case EGuessStatus::Not_Lowercase:
		std::cout << "Please use lowercase letters only \n";
		break;

	case EGuessStatus::NO_K:
		std::cout << "Please enter an isogram, all letters are unique \n";
		break;

	case EGuessStatus::Not_Characters:
		std::cout << "Do not use symbols or numbers \n";
		break;

	case EGuessStatus::OK:
		std::cout << "Figure out where to put Submit \n";
		break;

	default:
		return Guess; 
		break;
	}
	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? \n";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	if (Response[0] == 'Y' || Response[0] == 'y') {
		return true;
	}

	else if(Response[0] == 'N' || Response[0] == 'n') {
		return false;
	}
	return true;
}
