//Scott Snow
//s_snow2@u.pacific.edu
//ECPE 170
//2/6/13

#ifndef  CLUES_H
#define CLUES_H
//CLUE CLASS
typedef struct  {
    char *word; //Word to be found
    char *clue; //Clue given to user
    unsigned int x; //Starting x position
    unsigned int y; //Starting y position
    char direction; //Orientation 
    int f; //Checks if found
} Clue;
#endif
