#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "matrixHandler.h"
#include "movementHandler.h"

squareDef Sblock;
ZDef Zblock;
LDef Lblock;
IDef Iblock;
JDef Jblock;
TDef Tblock;

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
    putBlockInMat(1/*randomNumber*/,mat);
    Affiche(mat); //on l'affiche
    if (noConflict == 0){
      noConflict = movementHandler(mat,randomNumber); //gere les mouvements du bloc par le joueur
    }
    recopyOldMat(mat);
    Affiche(mat); //on l'affiche
  // }
  return 0;
}
