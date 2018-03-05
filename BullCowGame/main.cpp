#include <iostream>
#include <string>
#include "FBullCowGame.h"

std::string iAnswer = "Tingle";
int iLength = iAnswer.length();
std::string uGuess = "";
const int uGuesses = 5;

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	for (int i = 1; i <= MaxTries; i++)
	{
		GetGuess();

		//submit valid guess to the game
		//print number of bulls and cows

		std::cout << "Your guess was: " << uGuess << std::endl;

		if (BCGame.isValid(uGuess)) {
			std::cout << "True" << std::endl;
		}
		else {
			std::cout << "False" << std::endl;
		}

	}

	//TODO Summarise Game


	return;
}

void PrintIntro() {

	std::cout << "Welcome to Bulls and Cows, a mediocore word game. \n";
	std::cout << "Can you guess the " << iLength << " letter isogram I'm thinking off? \n \n";
	return;
}

std::string GetGuess() {

	int cTry = BCGame.GetCurrentTry();
	std::cout << "Try " << cTry << ". Enter your guess, biiiiiiiiiiiiiiitc-: ";
	std::getline(std::cin, uGuess);

	return uGuess;
}

void PrintBack(){

	std::cout << "Your guess was : " << uGuess << std::endl;
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? \n";
	std::string Response = "";
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
