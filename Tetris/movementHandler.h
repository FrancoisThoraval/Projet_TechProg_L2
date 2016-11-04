#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"

void movementHandler(char mat[Y][X],int randomNumber,int score, int line);
int canMove(char mat[Y][X], int typeOfBlock, int *position);
int ICanMove(char mat[Y][X], int *position);
int TCanMove(char mat[Y][X], int *position);
int JCanMove(char mat[Y][X], int *position);
int ZCanMove(char mat[Y][X], int *position);
int squareCanMove(char mat[Y][X]);
int LCanMove(char mat[Y][X], int *position);
int getNextMovement();
void Move(char mat[Y][X], int movement, int typeOfBlock,int *position);
void squareMoveLeft();
void squareMoveRight();
void squareMoveDown();
void ZMoveLeft();
void ZMoveRight(int *position);
void ZMoveDown();
void LMoveLeft(int *position);
void LMoveRight();
void LMoveDown();
void JMoveRight();
void JMoveLeft();
void JMoveDown();
void TMoveRight();
void TMoveLeft();
void TMoveDown();
void IMoveLeft();
void IMoveRight();
void IMoveDown();
void directDown(char mat[Y][X], int typeOfBlock, int position);
int ZcheckTurn(char mat[Y][X]);
int ScheckTurn(char mat[Y][X]);
