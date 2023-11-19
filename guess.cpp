#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seeding the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    
    int userGuess = 0, numberOfTries = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "\nEnter your guess: ";

    while (true) {
        cin >> userGuess;
        numberOfTries++;

        // Checking user's guess
        if (userGuess < secretNumber) 
		{
            cout << "Too low! Try again: ";
        } 
		else if (userGuess > secretNumber) 
		{
            cout << "Too high! Try again: ";
        } 
		else 
		{
            cout << "\nCongratulations! You guessed the right number: " << secretNumber << endl;
            cout << "It took you " << numberOfTries << " tries." << endl;
            break;
        }
    }

    return 0;
}

