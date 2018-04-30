#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
string Guess;
bool AskToPlayAgain();


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
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

void PlayGame() {
	// loop for the number of turns asking for guesses.
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++) {
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() {
	cout << "Enter your guess? ";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	cout << "Do you want to play again (y/n) ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

