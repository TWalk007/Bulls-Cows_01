/*This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction.  For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
FText Guess;
bool AskToPlayAgain();
FBullCowGame BCGame;  // instantiate a new game.

int main() {		
	
	do {
		PrintIntro();
		PlayGame();	
	} 
	while (AskToPlayAgain());

	return 0; //exit the application.
}

// Introducing the game.
void PrintIntro() {
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses.
	// TODO change from FOR to WHILE loop once we are validating tries.
	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = GetGuess(); // TODO make a check for valid guesses.


		// Submit the valid guess to the game and receive counts.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print the number of Bulls & Cows.


		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}

	// TODO add a game summary.
}

FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n) ";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

