//Scott Snow
//s_snow2@u.pacific.edu
//ECPE 170
//2/6/13

#include <stdio.h>
#include <stdlib.h>

/*Displays the Board*/
void showf(int rows, int cols, char** board)
{
	printf("Current puzzle:\n\n");
	int i;
	printf("\t");
	//Traverses the column array and displays column number with extra space if less than 10
	for (i=0; i< cols; i++)
	{
		if (i < 10)
			printf("  %i", i+1);
		else
			printf(" %i", i+1);
	}
	printf("\n\t  ");
	//Traverses the column array and prints dashes as a separator
	for (i=0; i< cols; i++)
		printf(" %c%c", '-', '-');
	printf("\n");
	//Prints out the board based on the characters board array
	for(i=0; i<rows; i++)
	{
		int j;
		//Prints the row number for each respective row
		printf("%i\t| ", i+1);
		for(j=0;j<cols;j++)
		{
			printf("%c  ", board[i][j]);
		}
		printf("\n");
	}
}
