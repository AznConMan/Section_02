#pragma once
#include <string>

using FString = std::string;
using int32 = int; 

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();

	void Reset(); //TODO more rich return value
	int32 GetMaxTries() const; 
	void CompareStrings() const;
	void EndGame();
	FString GetIsogram();
	FString AsciiArt();

	bool IsGameWon() const;
	int32 GetCurrentTry();
	bool CheckGuessValidity(FString);
	// Counts bulls and cows, increase turn #, assume valid guess
	FBullCowCount SubmitGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries; 
	FString MyIsogram;
};