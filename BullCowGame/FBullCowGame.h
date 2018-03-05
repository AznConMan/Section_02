#pragma once
#include <string>

//notice me senpai

class FBullCowGame {
public:
	FBullCowGame();

	void Reset(); //TODO more rich return value
	int GetMaxTries() const; 
	void CompareStrings() const;
	void EndGame();
	std::string GetIsogram();
	std::string AsciiArt();

	bool IsGameWon() const
		;
	int GetCurrentTry();
	bool CheckGuessValidity(std::string);
	// Create method for counting bulls and cows, increase turn #


private:
	int MyCurrentTry
	;
	int MyMaxTries; 
	std::string MyIsogram = "";
};