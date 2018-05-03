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

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase	
};

class FBullCowGame {

public:
	FBullCowGame(); // this is the constructor.

	int32 GetMaxTries() const;  // This is saying that the properties cannot change.
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);
	
private:
	// see constructor for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
};