/* This is a basic tic tac toe game. */

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID 3
#define TURNS 5

void printGrid(char arr[][GRID]);
bool checkFull(char arr[][GRID]);
bool checkWin(char grid[][GRID]);
int playerRow(void);
int playerCol(void);

int main(void)
{
    // printing game instructions
    printf("\n         TIC TAC TOE GAME\n\n");
    printf("----------------------------------------\n");
    printf("1. Pick a row and column from 0 to 2 to\n");
    printf("   mark your spot.\n");
    printf("2. Try to get 3 marks in a row, column\n");
    printf("   or diagonal to win the game.\n");
    printf("3. The computer gets to play first.\n");
    printf("\n           GOOD LUCK!~\n");
    printf("----------------------------------------");

    srand(time(0));
    bool gameOver = false;
    bool winner = false;
    int row1 = 0;
    int col1 = 0;
    int row2 = 0;
    int col2 = 0;

    // create an empty grid
    char grid[GRID][GRID];
    for (int i = 0; i < GRID; i++)
    {
        for (int j = 0; j < GRID; j++)
        {
            grid[i][j] = '_';
        }
    printf("\n");
    }

    // START OF THE GAME
    for (int i = 0; i < TURNS; i++)
    {
        winner = checkWin(grid);
        if (winner)
        {
            printf("The game is over.\n");
            return 0;
        }

        // get computer choice and check if valid
        printf("Computer played:\n");

        do
        {
            row2 = rand() % 3;
            col2 = rand() % 3;
        }
        while (grid[row2][col2] != '_');

        grid[row2][col2] = 'o';
        printGrid(grid);

        // check if the board is filled
        gameOver = checkFull(grid);

        if (gameOver)
        {
            printf("The game is over.\n");
            return 0;
        }

        winner = checkWin(grid);
        if (winner)
        {
            printf("The game is over.\n");
            return 0;
        }

        // get player choice and check if valid
        printf("\nYour turn!\n");

        do
        {
            row1 = playerRow();
            col1 = playerCol();
        }
        while (grid[row1][col1] != '_');

        printf("\nYou played:\n");
        grid[row1][col1] = 'x';
        printGrid(grid);
        printf("\n");

        winner = checkWin(grid);
        if (winner)
        {
            printf("The game is over.\n");
            return 0;
        }
    }

    return 0;
}

int playerRow(void)
{
    int r;
    do
    {
        r = get_int("Pick a row (0-2): ");
    }
    while (r < 0 || r > 2);

    return r;
}

int playerCol(void)
{
    int c;
    do
    {
        c = get_int("Pick a column (0-2): ");
    }
    while (c < 0 || c > 2);

    return c;
}

void printGrid(char arr[][GRID])
{
    for (int i = 0; i < GRID; i++)
    {
        for (int j = 0; j < GRID; j++)
        {
            printf("%c ", arr[i][j]);
        }
    printf("\n");
    }
}

bool checkFull(char arr[][GRID])
{
    for (int i = 0; i < GRID; i++)
    {
        for (int j = 0; j < GRID; j++)
        {
            if (arr[i][j] == '_')
            {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(char grid[][GRID])
{
    // rows
    for (int i = 0; i < GRID; i++)
    {
        int j = 0;

        if (grid[i][j] == 'x' && grid[i][j+1] == 'x' && grid[i][j+2] == 'x')
        {
            printf("You won!\n");
            return true;
        }

        if (grid[i][j] == 'o' && grid[i][j+1] == 'o' && grid[i][j+2] == 'o')
        {
            printf("The computer won!\n");
            return true;
        }
    }

    // columns
    for (int l = 0; l < GRID; l++)
    {
        int k = 0;

        if (grid[k][l] == 'o' && grid[k+1][l] == 'o' && grid[k+2][l] == 'o')
        {
            printf("The computer won!\n");
            return true;
        }

        if (grid[k][l] == 'x' && grid[k+1][l] == 'x' && grid[k+2][l] == 'x')
        {
            printf("You won!!\n");
            return true;
        }
    }

    // diagonals
    int m = 0, n = 0;

    if (grid[m][n] == 'x' && grid[m+1][n+1] == 'x' && grid[m+2][n+2] == 'x')
    {
        printf("You won!!\n");
        return true;
    }

    if (grid[m+2][n] == 'x' && grid[m+1][n+1] == 'x' && grid[m][n+2] == 'x')
    {
        printf("You won!!\n");
        return true;
    }

    if (grid[m][n] == 'o' && grid[m+1][n+1] == 'o' && grid[m+2][n+2] == 'o')
    {
        printf("The computer won!\n");
        return true;
    }

    if (grid[m+2][n] == 'o' && grid[m+1][n+1] == 'o' && grid[m][n+2] == 'o')
    {
        printf("The computer won!\n");
        return true;
    }
    return false;
}
