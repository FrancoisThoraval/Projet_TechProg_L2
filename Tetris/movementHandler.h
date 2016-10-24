#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"

void movementHandler(char mat[Y][X],int randomNumber);
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
void squareMoveRight();
void squareMoveDown();
void ZMoveLeft();
void ZMoveRight();
void ZMoveDown();
void JMoveRight();
void JMoveLeft();
void JMoveDown();
void TMoveRight();
void TMoveLeft();
void TMoveDown();
void IMoveLeft();
void IMoveRight();
void IMoveDown();
