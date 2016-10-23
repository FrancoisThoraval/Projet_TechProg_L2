#include "movementHandler.h"
#include "matrixHandler.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// TODO: movementHandler:
// - check type du bloc
// - en fonction du type de bloc observer l'evolution des points critiques de chaque bloc
//    ex: coin bas droite du carré si on peut aller a droite ou descendre
// - ecouter les touches de l'utilisateur pour recuperer les deplacements
// - effectuer le deplacement

int squareCanMove(){
  extern squareDef Sblock;
  int isPossibleR=0;
  int isPossibleD=0;
  int isPossibleL=0;
  int isPossible;
  if ((mat[Sblock.lineTwoY +1][Sblock.squareRightX] == 'o')||(mat[Sblock.lineTwoY +1][Sblock.squareLeftX] == 'o') || (mat[Sblock.lineTwoY +1][Sblock.squareLeftX] == '_')) {
    isPossibleD = 1;
  }
  if ((mat[Sblock.lineTwoY][Sblock.squareLeftX -1] == 'o') || (mat[Sblock.lineTwoY][Sblock.squareLeftX -1] == '#')) {
    isPossibleL = 1;
  }
  if ((mat[Sblock.lineTwoY][Sblock.squareRightX +1] == 'o') || (mat[Sblock.lineTwoY][Sblock.squareRightX +1] == '#')) {
    isPossibleR = 1;
  }
  isPossible = isPossibleR + isPossibleL + isPossibleD;
  return isPossible;
}

int ZCanMove(){
  extern ZDef Zblock;
  int isPossibleRTop=0;
  int isPossibleD=0;
  int isPossibleLTop=0;
  int isPossibleLMid=0;
  int isPossibleLBottom=0;
  int isPossibleRBottom=0;
  int isPossibleRMid=0;
  int isPossible;

  if ((mat[Zblock.lineOneY +1][Zblock.ZLeftTwoX]=='o')||(mat[Zblock.lineOneY +1][Zblock.ZLeftX]=='o')) {
    isPossibleD =1;
  }
  if ((mat[Zblock.lineOneY][Zblock.ZLeftTwoX -1]=='o')||(mat[Zblock.lineOneY][Zblock.ZLeftTwoX -1]=='#')) {
    isPossibleLTop=1;
  }
  if ((mat[Zblock.lineOneY][Zblock.ZRightTwoX +1]=='o')||(mat[Zblock.lineOneY][Zblock.ZRightX +1]=='#')) {
    isPossibleRTop=1;
  }
  if (mat[Zblock.lineTwoY][Zblock.ZMiddleX -1]=='o') {
    isPossibleLMid=1;
  }
  if ((mat[Zblock.lineThreeY][Zblock.ZLeftTwoX -1] =='o')||(mat[Zblock.lineThreeY][Zblock.ZLeftTwoX -1] =='#')) {
    isPossibleLBottom = 1;
  }
  if ((mat[Zblock.lineThreeY -1][Zblock.ZLeftTwoX] =='_')||(mat[Zblock.lineThreeY -1][Zblock.ZLeftX] =='o')||(mat[Zblock.lineThreeY -1][Zblock.ZMiddleX] =='o')||(mat[Zblock.lineThreeY -1][Zblock.ZRightX] =='o')||(mat[Zblock.lineThreeY -1][Zblock.ZRightTwoX] =='o')) {
    isPossibleD =1;
  }
  if ((mat[Zblock.lineThreeY][Zblock.ZRightTwoX +1] =='o')||(mat[Zblock.lineThreeY][Zblock.ZRightTwoX +1] =='#')) {
    isPossibleRBottom = 1;
  }
  if (mat[Zblock.lineTwoY][Zblock.ZRightX +1]=='o') {
    isPossibleRMid=1;
  }
  isPossible = isPossibleRTop + isPossibleRMid + isPossibleRBottom + isPossibleLBottom + isPossibleLTop + isPossibleLMid + isPossibleD;
  return isPossible;
}

int LCanMove(){
  extern LDef Lblock;
  int isPossibleD=0;
  int isPossibleL=0;
  int isPossibleR=0;
  int isPossibleBottomR=0;
  int isPossible;

  if ((mat[Lblock.lineThreeY -1][Lblock.LLeftX]=='o')||(mat[Lblock.lineThreeY -1][Lblock.LLeftX]=='_')||(mat[Lblock.lineThreeY -1][Lblock.LMiddleX]=='o')||((mat[Lblock.lineThreeY -1][Lblock.LMiddleX]=='_'))) {
    isPossibleD =1;
  }
  if ((mat[Lblock.lineOneY][Lblock.LLeftX -1]=='o')||(mat[Lblock.lineOneY][Lblock.LLeftX -1]=='#')) {
    isPossibleL =1;
  }
  if ((mat[Lblock.lineOneY][Lblock.LLeftX +1]=='o')||(mat[Lblock.lineOneY][Lblock.LLeftX +1]=='#')) {
    isPossibleR =1;
  }
  if ((mat[Lblock.lineThreeY][Lblock.LLeftX +1]=='o')||(mat[Lblock.lineThreeY][Lblock.LLeftX +1]=='#')) {
    isPossibleBottomR =1;
  }

  isPossible = isPossibleD + isPossibleR + isPossibleL + isPossibleBottomR;
  return isPossible;
}

int canMove(char mat[Y][X], int typeOfBlock){
  // extern squareDef Sblock;
  // extern ZDef Zblock;
  // extern LDef Lblock;
  // extern IDef Iblock;
  // extern JDef Jblock;
  // extern TDef Tblock;
  int isPossible =0;
  switch (typeOfBlock) {
    case 0: isPossible = squareCanMove();
      break;
    case 1: isPossible = ZCanMove();
      break;
    case 2: isPossible = LCanMove();
      break;
  }

  return isPossible;
}

int canGoRight(char mat[Y][X], int typeOfBlock){
  int isPossible = 0;

  return isPossible;
}

int canGoDown(char mat[Y][X], int typeOfBlock){
  int isPossible = 0;

  return isPossible;
}

int canGoLeft(char mat[Y][X], int typeOfBlock){
  int isPossible = 0;

  return isPossible;
}

int movementHandler(char mat[Y][X], int randomNumber){
  int noConflict =0; //Determine si le bloc ne peut plus descendre + bas

  return noConflict;
}
