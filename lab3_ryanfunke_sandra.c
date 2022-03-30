/* 
Author Name: Ryan Sigfrid Funke
Author Email: funker@purdue.edu
TA Name: Sandra Lee
Lab time: Friday, 11:30am

Project Title: Lab 3 - Functions and Recursion
Project Description: This project contains five functions which the user can select to run through a menu. This menu loops through and allows
the user to select a new function after running one, and upon exit of the program returns the number of functions ran. 
*/

#include <math.h> 
#include <stdio.h>
#include <string.h>

/* Function prototypes */
int factorial(int n);
int fibonacci(int n);
void runHanoi(int n, char x, char y, char z);
void reverseString(char* s, int a, int b);
void convertAscii(char* s, int a, int b);

int main()
{
    /* Variable initialization and declaration for program wide data */
    int counter = 0;
    int exitFlag = 0;
    char s[250];
    
    do{
        /* Variable initialization for each loop */
        int funcNum = 0;
        int n = 0;
        int i = 0;
        int j = 0;

        /* Menu for displaying the available functions to the user */
        printf("\n      Function Menu      \n");
        printf("\n=============================");
        printf("\nOption 1 = Factorials");
        printf("\nOption 2 = Fibonacci");
        printf("\nOption 3 = Towers of Hanoi");
        printf("\nOption 4 = Reverse a String");
        printf("\nOption 5 = Convert ASCII");
        printf("\n=============================");
        printf("\n\nEnter a number to select a function to run: ");
        scanf("%d", &funcNum);
        if((funcNum > 5) || (funcNum < 1))
        {
            printf("Error: Please enter a valid number!");
        }

        switch(funcNum) {
            case 1:
                /* Carries out the input and the output of the factorial function */
                n = 0;
                printf("\nPlease enter a number to list Factorials for: ");
                scanf("%d", &n);
                printf("\nThe factorial of %d is %d\n", n, factorial(n));
                printf("\n\nWould you like to run another program? (0 for Yes, 1 for No): ");
                scanf("%d", &exitFlag);
                counter++;
                break;
            case 2:
                /* Carries out the input and the output of the fibonacci sequence function */
                n = 0;
                printf("\nPlease enter a number to show a Fibonacci sequence for: ");
                scanf("%d", &n);
                printf("\nThe fibonacci sequence for %d is:", n);
                for (i = 1; i <= n; i++)
                {
                    printf(" %d", fibonacci(j));
                    j++;
                }
                printf("\n\nWould you like to run another program? (0 for Yes, 1 for No): ");
                scanf("%d", &exitFlag);
                counter++;
                break;
            case 3:
                /* Carries out the input and output of the towers of hanoi function */
                n = 0;
                printf("\nHow many disks would you like to use: ");
                scanf("%d", &n);
                printf("\nThe disks moved are: ");
                runHanoi(n, 'x', 'y', 'z');
                printf("\n\nWould you like to run another program? (0 for Yes, 1 for No): ");
                scanf("%d", &exitFlag);
                counter++;
                break;
            case 4:
                /* Carries out the input and output of the string reverse function */
                n = 0;
                s[250];
                printf("\nInput a string to reverse: ");
                scanf("%s", s);
                printf("\nThe input string was: %s", s);
                reverseString(s, 0, strlen(s) - 1);
                printf("\nThe output string is: %s", s);
                printf("\n\nWould you like to run another program? (0 for Yes, 1 for No): ");
                scanf("%d", &exitFlag);
                counter++;
                break;
            case 5:
                /* Carries out the input and output of the ASCII conversion function */
                n = 0;
                s[250];
                printf("\nInput a string to convert to binary: ");
                scanf("%s", s);
                convertAscii(s, 0, strlen(s) - 1);
                printf("\n\nWould you like to run another program? (0 for Yes, 1 for No): ");
                scanf("%d", &exitFlag);
                counter++;
                break;
        }   
    }while(exitFlag != 1);
    
    printf("\n\n Counter of functions ran: %d", counter);
    return counter;
}
/* This function takes an integer as input, which it then uses to return the factorial value of through recursion. */
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
        return n * factorial(n - 1);
}
/* This function takes an integer as input, which it then returns the fibonacci values of up until that point. It iterates recursively to print the entire sequence. */
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
       return fibonacci(n - 1) + fibonacci(n - 2);
}
/* This function takes an integer for the number of disks to run towers of hanoi with, and then three characters for the names of the pegs. It then prints all of the moves needed to complete the towers of hanoi puzzle. */
void runHanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from peg %c to peg %c", x, y);
    }
    else
    {
        runHanoi(n - 1, x , z, y);
        printf("\nMove disk %d from peg %c to peg %c", x, y);
        runHanoi(n - 1, y, x, z);
    }
}
/* This function takes a string as input and then a start and stop index, which it uses to recursively swap characters in the input string to reverse it. */
void reverseString(char *s, int a, int b)
{
    char c;

    if(a >= b)
    {
        return;
    }
    else
    {
        c = *(s + a);
        *(s + a) = *(s + b);
        *(s + b) = c;

        reverseString(s, ++a, --b);
    }
    
}
/* This function takes a string of input and then provides an output string of the binary values for each ASCII character within the string. */
void convertAscii(char* s, int a, int b)
{
    char c;
    int i = 0;
    printf("\nThe binary conversion of this string is:");
    while (i <= b)
    {
        int j = 1;
        int output = 0;
        int remainder = 0;

        c = (int)(*(s + i));
        while (c > 0)
        {
            remainder = c % 2;
            output = output + (j * remainder);
            c = c / 2;
            j = j * 10;
        }
        printf(" %d", output);
        i++;
        
    }
}
