#include "movementHandler.h"
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

// int squareCanMove(int downCornerLeftX, int downCornerLeftY, int rightCornerLeftX, int rightCornerLeftY){
//   return 0;
// }
//
// int canMove(char mat[Y][X], int typeOfBlock){
//   int isPossible =0;
//   switch (typeOfBlock) {
//     case 0: isPossible = squareCanMove()
//   }
//
//   return isPossible;
// }

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
