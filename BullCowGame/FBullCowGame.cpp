#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() { return MyCurrentTry; }
std::string FBullCowGame::GetIsogram() { return MyIsogram; }

 void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString ISOGRAM = "tingle";
	MyIsogram = ISOGRAM;

	MyCurrentTry = 1;
	return;
}
void FBullCowGame::CompareStrings() const {
	return;
}

void FBullCowGame::EndGame() {
	return;
}

FString FBullCowGame::AsciiArt() {
	return 0;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}


bool FBullCowGame::CheckGuessValidity(FString) {
	return false;
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	//increment turn counter
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;

	//loop through all letters in the guess
	int32 MyIsogramLength = MyIsogram.length();
	int32 MyGuessLength = Guess.length();
	for (int32 i = 0; i < MyIsogramLength; i++) {
		for (int32 j = 0; j < MyGuessLength; j++)
		{
			//compare each letter to isogram
			//if they match then
			if (Guess[j] == MyIsogram[i] && i==j)
			{
				//increment bulls
				BullCowCount.Bulls++;
			}
			else if (Guess[j] == MyIsogram[i])
			{
				BullCowCount.Cows++;
			}
		}
	}
	return BullCowCount;
}