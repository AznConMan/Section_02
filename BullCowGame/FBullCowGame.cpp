#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() { return MyCurrentTry; }
std::string FBullCowGame::GetIsogram() { return MyIsogram; }

 void FBullCowGame::Reset() {
	const int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	return;
}
void FBullCowGame::CompareStrings() const {
	return;
}

void FBullCowGame::EndGame() {
	return;
}

std::string FBullCowGame::AsciiArt() {
	return 0;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}



bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}