#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "matrixHandler.h"
#include "movementHandler.h"

// int const X=12;
// int const Y=14;
// #define Y 14
// #define X 12


// int movementHandler(char mat[Y][X]){
//   int noConflict =0; //Determine si le bloc ne peut plus descendre + bas
//
//   return noConflict;
// }

int main() {
  // char mat[X][Y];
  int gameOn =0;
  int oldNumber = -1;
  // int randomNumber;
  int noConflict =0;
  initMatrix(mat); //on initialise la matrice

  // while (gameOn != 1) { //On boucle tant que le jeu est lancé
    do {
      randomNumber = randomize();
    } while(randomNumber == oldNumber);
    oldNumber = randomNumber;
    //On met le bloc dans la matrice
    putBlockInMat(randomNumber,mat);
    Affiche(mat); //on l'affiche
    if (noConflict == 0){
      noConflict = movementHandler(mat,randomNumber); //gere les mouvements du bloc par le joueur
    }
    recopyOldMat(mat);
    Affiche(mat); //on l'affiche
  // }
  return 0;
}
