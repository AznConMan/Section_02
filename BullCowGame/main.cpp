/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class. 
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FText iAnswer = "Tingle";
int32 iLength = iAnswer.length();
FText uGuess = "";
const int32 uGuesses = 5;

void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintBack(); 
bool AskToPlayAgain();

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
	std::cout << MaxTries << std::endl;
	FBullCowCount BullCowCount;

	std::cout << BullCowCount.Bulls << std::endl;
	std::cout << BullCowCount.Cows << std::endl;

	for (int32 i = 1; i <= MaxTries; i++)
	{
		GetGuess();

		//submit valid guess to the game

		FBullCowCount BullCowCount = BCGame.SubmitGuess(uGuess);

		//print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
	}

	//TODO Summarise Game


	return;
}

void PrintIntro() {

	std::cout << "Welcome to Bulls and Cows, a mediocore word game. \n";
	std::cout << "Can you guess the " << iLength << " letter isogram I'm thinking off? \n \n";
	return;
}

FText GetGuess() {

	int32 cTry = BCGame.GetCurrentTry();
	std::cout << "Try " << cTry << ". Enter your guess, biiiiiiiiiiiiiiitc-: ";
	std::getline(std::cin, uGuess);

	return uGuess;
}

void PrintBack(){

	std::cout << "Your guess was :" << uGuess << std::endl;
	std::cout << std::endl;
	return;
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
