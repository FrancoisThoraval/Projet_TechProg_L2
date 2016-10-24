#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"

int movementHandler(char mat[Y][X],int randomNumber);
int canMove(char mat[Y][X], int typeOfBlock);
int ICanMove(char mat[Y][X]);
int TCanMove(char mat[Y][X]);
int JCanMove(char mat[Y][X]);
int ZCanMove(char mat[Y][X]);
int squareCanMove(char mat[Y][X]);
int LCanMove(char mat[Y][X]);
int getNextMovement();
void Move(char mat[Y][X], int movement, int typeOfBlock);
void squareMoveLeft();
