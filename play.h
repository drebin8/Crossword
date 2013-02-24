//Scott Snow
//s_snow2@u.pacific.edu
//ECPE 170
//2/6/13

#ifndef PLAY_H
#define PLAY_H

//Used to check if an element has been found in the array
int find_index(int a[], int num_elements, int value);

void play(char** board, int words, Clue *clues, int x, int y, int gameOver);

#endif //PLAY_H
