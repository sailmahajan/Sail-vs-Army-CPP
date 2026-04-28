#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentPlayer = 'X';

void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

void playerMove() {
    int choice;
    cout << "Player " << currentPlayer << " ki baari. 1-9 dabao: ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col]!= 'X' && board[row][col]!= 'O') {
        board[row][col] = currentPlayer;
    } else {
        cout << "Galat move! Phir se try kar." << endl;
        playerMove();
    }
}

void switchPlayer() {
    if(currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int main() {
    drawBoard();
    playerMove();
    drawBoard();
    switchPlayer();
    playerMove();
    drawBoard();
    return 0;
}
