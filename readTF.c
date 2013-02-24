//Scott Snow
//s_snow2@u.pacific.edu
//ECPE 170
//2/6/13

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "clue.h"

//For loop to extract values from the .txt file
Clue* readTF( FILE* Crossword, int Words )
{
	char line[1024];//char array to take in user input to store in cw puzzle
	Clue *Clues;
	//Allocate memory for Clues array
	Clues = (Clue *)malloc(sizeof(Clue)*Words);
	int i;
	for(i = 0; i < Words; i++)
	{
		//allocates memory to the word and clue of each clue element
		Clues[i].word = (char *)malloc(sizeof(char *) * 256);
		Clues[i].clue = (char *)malloc(sizeof(char *) * 256);
		//take in input from the file - returns the direction, and x/y start of each clue
		fscanf(Crossword, "%c %i %i ", &Clues[i].direction, &Clues[i].x, &Clues[i].y);
		int j=0;
		//While character is not a newline, input is taken from file and stored in line
		do
			fscanf(Crossword, "%c", &line[j]);
		while (line[j++] != '\n');
		line[j-1] = 0;	j--;
		//printf("%s\n", line);
		int k;
		//k is the variable that iterates over line
		for(k=0; k < j && line[k] != ' '; k++)
			Clues[i].word[k] = line[k];
		Clues[i].word[j] = 0;
		int l = 0;
		//Stores the loaded clue into the Clues array
		for(; k < j; k++)
			Clues[i].clue[l++] = line[k];
		Clues[i].clue[l] = 0;
	}
	return Clues;
}
