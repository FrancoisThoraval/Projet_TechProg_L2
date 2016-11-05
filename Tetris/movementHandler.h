#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"

void movementHandler(char mat[Y][X],int randomNumber,int score, int line);
int canMoveV(char mat[Y][X]);
int canMoveH(char mat[Y][X], int side);
int getNextMovement();
void Move(char mat[Y][X], int movement, int typeOfBlock,int *position);
void squareMoveLeft();
void squareMoveRight();
void squareMoveDown();
void directDown(char mat[Y][X], int typeOfBlock, int position);
