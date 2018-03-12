#pragma once
#include <string>
#include <algorithm>

using FString = std::string;
using int32 = int; 

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	Invalid,
	OK, 
	NO_K,
	Has_Upper,
	Not_Characters,
	Wrong_Length
};

class FBullCowGame 
{
public:
	FBullCowGame();

	void Reset(); //TODO more rich return value
	void EndGame();
	void CompareStrings() const;

	int32 GetCurrentTry();
	int32 GetMaxTries() const;
	int32 GetIsogramLength() const;

	FString GetIsogram();
	FString AsciiArt();
	FString SortGuess(FString Guess);

	bool IsGameWon() const;

	// Counts bulls and cows, increase turn #, assume valid guess
	FBullCowCount SubmitGuess(FString Guess);

	EGuessStatus CheckGuessValidity(FString Guess) const;


private:
	int32 MyCurrentTry;
	int32 MyMaxTries; 
	FString MyIsogram;
};