#pragma once
#include <string>
#include <iostream>

using FString = std::string;
using int32 = int;

// two integers initialized at zero.
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame {

public:
	FBullCowGame(); // this is the constructor.

	int32 GetMaxTries() const;  // This is saying that the properties cannot change.
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString) const; // TODO make a more rich return value.

	void Reset();  // TODO make a more rich return value.
	FBullCowCount SubmitGuess(FString);
	
private:
	// see constructor for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};