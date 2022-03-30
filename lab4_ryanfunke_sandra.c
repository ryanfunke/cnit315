/* 
Author Name: Ryan Sigfrid Funke
Author Email: funker@purdue.edu
TA Name: Sandra Lee
Lab time: Friday, 11:30am

Project Title: Lab 4 - Functions, Pointers and Recursion
Project Description: Using mutual recursion, this program takes an already declared maze in the mazeRep declaration which is then navigated through in order to find the
path from the starting 'S' character to the endpoint 'G' character. Invalid spots are marked with '#', and valid but not yet traversed spots are marked with '.'. When a 
valid spot is found, the program will mark it with a '+' character.
*/

/* Some constant declarations to help with parameters of methods */
#define ROWS 6
#define COLUMNS 6
#include <stdio.h>

/* Function prototypes & declarations */
void mazeGo(char mazeRep[ROWS][COLUMNS], int x, int y);
char mazeRep[ROWS][COLUMNS] = {{'S', '#', '#', '#', '#', '#'}, 
                               {'.', '.', '.', '.', '.', '#'}, 
                               {'#', '.', '#', '#', '#', '#'}, 
                               {'#', '.', '#', '#', '#', '#'}, 
                               {'.', '.', '.', '#', '.', 'G'}, 
                               {'#', '#', '.', '.', '.', '#'}};

int main()
{
    /* Initial coordinates for path traveling */
    int x = 0;
    int y = 0;
    printf("start\n");
    /* recursion smursion */
    mazeGo(mazeRep, x, y + 1);
    printf("end\n");
    return 0;
}

void mazeGo(char mazeRep[ROWS][COLUMNS], int x, int y)
{
  
    if (mazeRep[y][x] == 'G')
    {
        /* Throw final print loop in here */
        exit(0);
    }
    else if (x < 0 || x >= ROWS)
    {
        /* Testing for x coordinate boundaries */
        return;
    }
    else if (y < 0 || y >= COLUMNS)
    {
        /* Testing for y coordinate boundaries */
        return;
    }
    else if (mazeRep[y][x] == '#')
    {
        /* Testing for 'wall' spot in the maze */
        return;
    }
    else if (mazeRep[y][x] == '.')
    {
        /* Tests for open, valid spot and then calls another instance of the function through recursion to continue */
        mazeRep[y][x] = '+';
        printf("\n");
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                printf("%c ", mazeRep[i][j]);
            }
        printf("\n");
        }
        mazeGo(mazeRep, x + 1, y);
        mazeGo(mazeRep, x, y + 1);
        mazeGo(mazeRep, x - 1, y);
        mazeGo(mazeRep, x, y - 1);
    }
    else if (mazeRep[y][x] == '+')
    {
        /* Testing ror boundaries of already discovered path */
        return;
    }
    else
    {
        return;
    }
}
