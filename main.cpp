#include <iostream>

const int SIZE = 3; // Size of the Tic Tac Toe board
char board[SIZE][SIZE] = { ' ' }; // Initialize the board with empty spaces
char currentPlayer = 'X'; // Current player, starting with 'X'

// Function prototypes
void displayBoard();
bool checkWin();
bool checkDraw();
void switchPlayer();
bool isValidMove(int row, int col);
void makeMove(int row, int col);
void resetBoard();

int main() {
    char playAgain;

    do {
        resetBoard();
        bool gameEnded = false;

        while (!gameEnded) {
            displayBoard();

            int row, col;
            std::cout << "Player " << currentPlayer << ", enter row and column (0, 1, 2): ";
            std::cin >> row >> col;

            if (isValidMove(row, col)) {
                makeMove(row, col);

                if (checkWin()) {
                    displayBoard();
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    gameEnded = true;
                } else if (checkDraw()) {
                    displayBoard();
                    std::cout << "The game is a draw!\n";
                    gameEnded = true;
                } else {
                    switchPlayer();
                }
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}

void displayBoard() {
    std::cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << " " << board[i][j];
            if (j < SIZE - 1) std::cout << " |";
        }
        std::cout << "\n";
        if (i < SIZE - 1) std::cout << "---|---|---\n";
    }
    std::cout << "\n";
}

bool checkWin()
{
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool isValidMove(int row, int col)
{
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

void makeMove(int row, int col)
{
    board[row][col] = currentPlayer;
}

void resetBoard()
{
    for (int i = 0; i < SIZE; ++i)
        {
        for (int j = 0; j < SIZE; ++j)
        {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}
