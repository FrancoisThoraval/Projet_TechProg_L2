#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "tetris.h"
#include "scoreHandler.h"
#include "musicHandler.h"

void menu(float *difficulty_O_Meter, Mix_Music *menuMusic);
int menuMovement(int *pitem, float *difficulty_O_Meter, Mix_Music *menuMusic);
void displayMenu(int i, float *difficulty_O_Meter);
void displayMenuGameOver(int i);
int menuGameOverMovement(int *pitem, int *score, int *line, float *difficulty_O_Meter,int *tries, int mode);
void menuGameOver(float *difficulty_O_Meter ,int *score, int *line, int *tries, int mode);
void menuOptions(float *difficulty_O_Meter, Mix_Music *menuMusic);
void callMenuWithMusic(float *difficulty_O_Meter);
void menuGameModeTwo(float *difficulty_O_Meter, Mix_Music *menuMusic);
