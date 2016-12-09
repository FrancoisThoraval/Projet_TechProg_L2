#include "matrixHandler.h"
#include "definition.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <sys/time.h>
#include "musicHandler.h"


void movementHandler(char mat[Y][X],int randomNumber,int *score, int *line, coordBlock *block, float seconds, int level, int tries);
void testPrintInfo(int *position, coordBlock *block);
int canMoveV(char mat[Y][X], coordBlock *block);
int canMoveH(char mat[Y][X], int side, coordBlock *block);
int getNextMovement(char mat[Y][X],int score, int line);
void Move(char mat[Y][X], int movement, int typeOfBlock,int *position, int *score, coordBlock *block);
void moveDown(coordBlock *block);
void moveDownEvery(int seconds, coordBlock *block, int score, int line, int randomNumber, int position);
void moveRight(char mat[Y][X], coordBlock *block);
void moveLeft(char mat[Y][X], coordBlock *block);
void directDown(char mat[Y][X], int typeOfBlock, int position, coordBlock *block);
