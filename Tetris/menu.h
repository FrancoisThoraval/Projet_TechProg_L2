#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "tetris.h"
#include "scoreHandler.h"
void menu();
int menuMovement(int *pitem, int *difficulty_O_Meter);
void displayMenu(int i);
void displayMenuGameOver(int i);
int menuGameOverMovement(int *pitem, int *score, int *line);
void menuGameOver(int *score, int *line);
