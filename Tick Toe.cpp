#include <iostream>
using namespace std;

void board(char position[9]) {
    cout << "     |     |     " << endl;
    cout << "  " << position[0] << "  |  " << position[1] << "  |  " << position[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << position[3] << "  |  " << position[4] << "  |  " << position[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << position[6] << "  |  " << position[7] << "  |  " << position[8] << endl;
    cout << "     |     |     " << endl;
}

char playerchng(char playerchar) {
    return (playerchar == 'O') ? 'X' : 'O';
}

bool checkingwinner(char position[9]) {
    // Rows
    if ((position[0] == position[1] && position[1] == position[2] && position[0] != ' ') ||
        (position[3] == position[4] && position[4] == position[5] && position[3] != ' ') ||
        (position[6] == position[7] && position[7] == position[8] && position[6] != ' ') ||
        // Columns
        (position[0] == position[3] && position[3] == position[6] && position[0] != ' ') ||
        (position[1] == position[4] && position[4] == position[7] && position[1] != ' ') ||
        (position[2] == position[5] && position[5] == position[8] && position[2] != ' ') ||
        // Diagonals
        (position[0] == position[4] && position[4] == position[8] && position[0] != ' ') ||
        (position[2] == position[4] && position[4] == position[6] && position[2] != ' ')) {
        return true;
    }
    return false;
}

bool playagain() {
    char again;
    cout << "Wanna Play again? (Y/N) : ";
    cin >> again;
    return (again == 'Y' || again == 'y');
}

int main() {
    char position[9];
    int location;
    char playerchar;
    bool gameRunning;

    do {
        // Resetting the game state
        for (int i = 0; i < 9; ++i) position[i] = ' ';
        playerchar = 'X';
        gameRunning = true;

        while (gameRunning) {
            system("cls");
            board(position);

            cout << "Player " << playerchar << ", enter the box number (1-9): ";
            while (!(cin >> location) || location < 1 || location > 9 || position[location - 1] != ' ') {
                cout << "Invalid input. Please enter a number between 1 and 9 for an empty box: ";
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            }

            position[location - 1] = playerchar;
            playerchar = playerchng(playerchar);

            if (checkingwinner(position)) {
                gameRunning = false;
                system("cls");
                board(position);
                cout << "Congratulations! Player " << playerchng(playerchar) << " has won the game!" << endl;
            }
            else if (find(begin(position), end(position), ' ') == end(position)) {
                gameRunning = false;
                system("cls");
                board(position);
                cout << "The game is a draw." << endl;
            }
        }
    } while (playagain());

    return 0;
}
