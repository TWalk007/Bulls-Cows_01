#include "FBullCowGame.h"


FBullCowGame::FBullCowGame() { Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return 	MyHiddenWord.length(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}


bool FBullCowGame::IsGameWon() const { 
	return false; 
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const { 
	return EWordStatus::OK;  // TODO make actual error.
}

// receives a valid guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount; // this initializes BullCowCount

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {// we don't include the length of the word (not <=), just less than because the count starts at 0.	{
		// compare letters against the hidden word.
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { //if the indices are the same (same location in the word)
					BullCowCount.Bulls++; // increment bulls
				}
				else {
					BullCowCount.Cows++; // increment cows
				}
			}
		}
	}
	return BullCowCount;

}
