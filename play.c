//Scott Snow
//s_snow2@u.pacific.edu
//ECPE 170
//2/6/13

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "clue.h"

//Used to check if an element has been found in the array
int find_index(int a[], int num_elements, int value)
{
   int i;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i] == value)
	 {
	    return 1;  /* it was found */
	 }
   }
   return(0);  /* if it was not found */
}

void play(char** board, int words, Clue *clues, int x, int y, int gameOver)
{
	char answer[256];//Answer to the specified clue
	int solve; //Variable to hold the user's desired solution to be tried
	int i; //Counter
	int checkFound[words]; //Array that holds 1->words, but changes elements to 0 as they are found
	int wasFound[words]; //Array that holds 0s, but adds numbers as lines are solved
	char direction[11]; //Used to hold word version of orientation
	//Traverse 0->words-1 to add required numbers to the arrays specified
	for (i=0; i<words; i++)
	{
		checkFound[i] = i+1;
		wasFound[i] = 0;
	}
	//Fills board with updated entries
	for (i=0; i<words; i++)
		board = updatef(board, clues, i);
	showf(x, y, board); //Display board
	//Play the game until the game has been completed or exited
	do
	{
		//initial header text to display what is being shown
		printf("\t");
		for (i=0; i<y; i++)
			printf("***");
		int j; //Iterator
		//Describes each item to be given to the user
		printf("\nClues: \n");
		printf("#  Direction  \t row  col   Hint\n");
		printf("---------------------------------\n");
		//Iterator over # words, will display each hint
		for(j=0; j<words;j++)
		{
			//Checks if direction is H or V then displays the associated direction as a word
			if (clues[j].direction == 'H')
				strcpy(direction, "Horizontal");
			else if (clues[j].direction == 'V')
				strcpy(direction, "Vertical");
			//Checks if a hint has been found, then displays formatted text
			if (find_index(checkFound, words, j+1) == 1)
			{
				printf("%i: %s\t  %i ", j+1, direction, clues[j].x);
				printf("   %i   %s\n", clues[j].y, clues[j].clue);
			}
		}
		printf("\n");
		//Checks user input for validity or if it's been solved
		//Loop continues until valid (non-solved) number is entered
		do{
			printf("Enter -1 to exit\n");
			printf("Which clue do you want to solve?: ");
			//If the user enters invalid input (string, char, etc), set solve to 0 so it loops again
			if (scanf("%i", &solve) < 1)
				solve = 0;
			//Quit if the user types -1
			if (solve == -1)
				return;
			//Checks if clue has been solved
			if (find_index(wasFound, words, solve) == 1)
			{
				printf("That clue has been solved\n");
				solve = 0;
			}
			//Notifies user if input is invalid
			else if (find_index(checkFound, words, solve) == 0)
			{
				printf("That clue is invalid\n");
				solve = 0;
			}
		}while(solve<1 || solve>words);	
		
		
		//Displays current hint and requests user input for solution to current line
		printf("Current hint: %s\n", clues[solve-1].clue);
		printf("Enter your solution: ");
		scanf("%s", answer);
		
		//Converts user input solution to upper case
		for(i=0; answer[i]; i++)
			answer[i] = toupper(answer[i]);

		//Checks if the user typed in the right answer
		if(strcmp(answer, clues[solve-1].word) != 0)
		{
			printf("WRONG ANSWER\n");
			showf(x, y, board);
		}
		//If user input is correct, do this
		else
		{
			printf("\nCorrect!\n\n");
			clues[solve-1].f = 1; //Sets found state to 1 (found)
			wasFound[solve-1] = solve; //Adds solved problem to validity checker array
			checkFound[solve-1] = 0; //Removes solved problem from available array
			board = updatef(board, clues, solve-1); //Updates board with solved clue
			showf(x, y, board); //Displays the board
			gameOver++; //Increments gameOver counter
		}
	}while(gameOver != words); //Ends the game when all words have been found
	printf("\nYou beat the crossword puzzle! Congratulations!\n\n");
	return;
}
