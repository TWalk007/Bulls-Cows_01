#include <iostream>
#include <string>

using namespace std;

int main()
{	
	// Introducing the game.
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	// get a guess from the player.
	cout << "What is your guess? ";
	string Guess = "";
	cin >> Guess;

	// repeat the guess back to them.
	cout << "Your guess was: " << Guess << endl;

	return 0;
}