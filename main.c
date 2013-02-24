//Scott Snow
//s_snow2@u.pacific.edu
//ECPE 170
//2/6/13

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "showf.h"
#include "updatef.h"
#include "clue.h"
#include "createArray.h"
#include "readTF.h"
#include "play.h"

//char updatef( char*, int, int );
int main(  )
{
	int gameOver = 0;
	char filename[256] = "cw.txt";//files name
	char** board;//dynamic array of the board
	FILE* crossword;//file pointer to the file
	int x, y, words;//size of array & number of words in the puzzle
	Clue *clues;
	printf("CROSSWORD PUZZLE GAME\n\n");
	//Ask player for name of file.
	printf("Enter name of text file: ");
	printf("(default is cw.txt): ");
	//Read input from the user
	scanf("%s", filename);
	//printf("\n");
	//Open the file
	crossword = fopen(filename, "r");
	//if the crossword file does not exist, use the default that i included
	if(crossword == NULL)
	{
		crossword = fopen("cw.txt", "r");
		strcpy(filename, "cw.txt");
	}
	//If the user inputs a valid file, use it for the game
	if(crossword != NULL)
	{
		printf("Loading game file: %s\n", filename);
		fscanf(crossword, "%i %i %i\n", &x, &y, &words);
		printf("Game is %i rows x %i cols with %i words\n", x, y, words);
		clues = (Clue *)malloc(sizeof(Clue)*words);
		
		clues = readTF(crossword, words);
		fclose(crossword);
	}
	//If the user inputs an invalid file and default is not present, return error
	else
	{
		//if the file didn't open.
		perror(filename);
	}
	//Creates board to be passed through program that will hold characters
	board = createArray(x, y);
	//Plays game until completion
	play(board, words, clues, x, y, gameOver);
	
	//Frees board and clues from memory
	free(board);
	free(clues);
	return 0;
}
