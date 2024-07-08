#include <iostream>
using namespace std;

class Game
{
public:
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';

    void drawBoard()
    {
        cout << "Game display:\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " ";
                if (j < 2)
                {
                    cout << "| ";
                }
            }
            cout << endl;
            if (i < 2)
            {
                cout << "---------";
            }
            cout << endl;
        }
    }

    bool checkWin()
    {
        // Check rows
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        {
            return true;
        }

        return false;
    }

    bool checkDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    return false;
                }
            }
        }
        return true;
    }

    void start()
    {
        while (true)
        {
            drawBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
            {
                board[row][col] = currentPlayer;

                if (checkWin())
                {
                    drawBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }
                else if (checkDraw())
                {
                    drawBoard();
                    cout << "The game is a draw!\n";
                    break;
                }

                // Switch player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            else
            {
                cout << "Invalid move. Try again.\n";
            }
        }
    }
};

int main()
{
    Game g1;
    g1.start();
    return 0;
}
