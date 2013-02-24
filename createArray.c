#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "clue.h"

/*Creates the board*/
char** createArray(int rows, int cols)
{
	int i, j;//counters to loop through arrays
	char **myArray;
	//Allocate a 1xrows array to hold pointers to more arrays
	myArray = calloc(rows, sizeof (int*));
	if(myArray == NULL) //If out of memory, return error
	{
		printf("FATAL ERROR: out of memory: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	//For loop to allocate memory for each row
	for(int i=0; i<rows; i++)
	{
		myArray[i] = calloc(cols, sizeof(int));
		if(myArray[i] == NULL)//If out of memory, return error
		{
			printf("FATAL ERROR: out of memory: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	//Initializes all elements to '#'
	for(i=0; i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			myArray[i][j]='#';
		}
	}
	return myArray;
}
