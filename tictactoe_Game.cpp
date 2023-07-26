#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentPlayer = 'X';

void drawBoard()
{
    cout<< "Tic Tac Toe\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j]<< " ";
        }
        cout<<endl;
    }
}

bool isMoveValid(int choice)
{
    if(choice<1||choice>9)
        return false;

    int row = (choice-1)/3;
    int col = (choice-1)%3;

    if(board[row][col]=='X' || board[row][col]=='O')
        return false;

    return true;
}

void makeMove(int choice)
{
    int row = (choice-1)/3;
    int col = (choice-1)%3;
    board[row][col] = currentPlayer;
}

bool checkWin()
{
    // Check rows, Columns, and diagonals for a win
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw()
{
    // Check if the board is full
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X' && board[i][j]!='O')
                return false;
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer=='X') ? 'O' : 'X';
}

int main()
{
    int choice;
    bool playAgain = true;

    while (playAgain)
    {
        // Initialize the board and the currentPlayer for a new game
        currentPlayer = 'X';
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                board[i][j] = '1' + i*3 + j;
            }
        }
        
        bool gameover = false;

        while(!gameover)
        {
            drawBoard();

            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            if(!isMoveValid(choice))
            {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            makeMove(choice);

            if(checkWin())
            {
                drawBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameover = true;
            }
            else if(checkDraw())
            {
                drawBoard();
                cout << "It's a draw!\n";
                gameover = true;
            }
            else
            {
                switchPlayer();
            }
        }

        char playAgainChoice;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgainChoice;

        playAgain = (playAgainChoice == 'Y' || playAgainChoice == 'y');
    }

    cout << "Thanks for playing Tic Tac Toe!\n";
    return 0;
}
