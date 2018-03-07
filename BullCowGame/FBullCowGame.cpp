#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetIsogramLength() const {	return MyIsogram.length();	}

int32 FBullCowGame::GetCurrentTry() { return MyCurrentTry; }
FString FBullCowGame::GetIsogram() { return MyIsogram; }

 void FBullCowGame::Reset() 
 {
	constexpr int32 MAX_TRIES = 8;
	const FString ISOGRAM = "tingle";
	
	MyMaxTries = MAX_TRIES;
	MyIsogram = ISOGRAM;
	MyCurrentTry = 1;
	return;
}

void FBullCowGame::CompareStrings() const 
{
	return;
}

void FBullCowGame::EndGame() 
{
	return;
}

FString FBullCowGame::AsciiArt() 
{
	return 0;
}


bool FBullCowGame::IsGameWon() const 
{
	return false;
}

FString FBullCowGame::SortGuess(FString Guess)
{
	sort(Guess.begin(), Guess.end());
	return Guess;
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

//FIsIsogram FBullCowGame::IsIsogram(FString Guess)
//{
//	FIsIsogram IsValidIsogram;
//
//	FString SortedGuess = Guess;
//	sort(Guess.begin(), Guess.end());
//
//	for (int32 i = 0; i < Guess.length(); i++)
//	{
//		if (Guess[i] == Guess[i + 1])
//		{
//			IsValidIsogram.IsIsogram = true;
//		}
//		else
//		{
//			IsValidIsogram.IsIsogram = false;
//		}
//	}
//	return IsValidIsogram;
//}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{
	if (false)//if the guess isn't an isogram
	{
		return EGuessStatus::NO_K;
	}
	else if (false)//if it isn't all lower case
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetIsogramLength())//if the length is wrong 
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

//EIsIsogram FBullCowGame::IsIsogram(FString Guess) const
//{
//	sort(Guess.begin(), Guess.end());
//	for (int32 i = 0; i < Guess.length(); i++)
//	{
//		if (Guess[i] == Guess[i + 1])
//		{
//			return EIsIsogram::NO_K;
//		}
//		else
//		{
//			return EIsIsogram::OK;
//		}
//	}
//}