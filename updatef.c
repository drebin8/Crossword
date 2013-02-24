//Scott Snow
//s_snow2@u.pacific.edu
//ECPE 170
//2/6/13

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clue.h"

/*Updates specified elements of the board*/
char** updatef(char** myBoard, Clue *cluesA, int solve)
{
	int h, v, i; //v is for column number, h is row number, i is for traversal
	v = cluesA[solve].x-1; //Sets column number to start update
	h = cluesA[solve].y-1; //Sets row number to start update
	
	//Finds length of word being inserted into board
	int len = strlen(cluesA[solve].word);
	//Inserts elements into board
	for(i = 0; i < len; i++)	
	{
		//If the clue has been found, insert the word
		if(cluesA[solve].f == 1){
			myBoard[v][h] = cluesA[solve].word[i];
		}
		//If the clue has not been found, insert _
		else myBoard[v][h] = '_';
		//Decides whether to traverse rows or columns
		if(cluesA[solve].direction == 'H')
		{
			h++;//Traverses columns <>
		}
		else
		{
			v++;//Traverses rows ^v
		}
	}
	return myBoard;
}
