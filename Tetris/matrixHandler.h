#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"
#include "scoreHandler.h"

/*
Description:

- PROCEDURE errorHandler (errorCode: entier) -> gère les erreurs potentielles
- PROCEDURE Affiche (mat[Y,X]: matrice de caractères) -> Affiche la matrice avec les bordures
- PROCEDURE square to iail (mat[Y,X]: matrice de caractères) -> Cree un carré/ Z / L / J / T / I dans la matrice
- PROCEDURE putBlockInMat (randomNumber: entier, mat[Y,X]: matrice de caractères) -> définit quel bloc on met dans la matrice en fonction d'un nombre aléatoire
- PROCEDURE recopyOldMat (mat[Y,X]: matrice de caractères) -> une fois que le bloc est joué et a atteint sa position finale, remplace tous les 'x' du bloc par des 'o' représentant les blocs placés
- PROCEDURE initMatrix (mat[Y,X]: matrice de caractères) -> Cree la matrice avec les bordures et remplie de caractères vides
- FONCTION randomize (): entier -> Génère un nombre aléatoire entre 0 et 5 définissant le type de bloc qui sera généré

*/

char mat[Y][X];
int randomNumber;

typedef struct{
  int leftX;
  int middleX;
  int rightX;
  int lineOneY;
  int lineTwoY;
  int lineThreeY;
  int lineFourY;
}coordBlock;

void errorHandler(int errorCode);
void Affiche(char mat[Y][X], int score, int line);

// Design blocs
void square(char mat[Y][X], int isSet);
void zeee(char mat[Y][X], int isSet, int position);
void leee(char mat[Y][X], int isSet, int position);
void jeee(char mat[Y][X], int isSet, int position);
void teee(char mat[Y][X], int isSet, int position);
void iail(char mat[Y][X], int isSet, int position);
void seee(char mat[Y][X], int isSet, int position);

void putBlockInMat(int randomNumber,char mat[Y][X], int isSet, int position);
void blockEnd(char mat[Y][X]);
void initMatrix(char mat[Y][X]);
int randomize();
void matrixMovement(char mat[Y][X], int typeOfBlock, int position);
int gameOver(char mat[Y][X]);
void initCoordStruct();
