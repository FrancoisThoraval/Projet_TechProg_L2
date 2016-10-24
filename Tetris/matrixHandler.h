#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"

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

typedef struct {
  int lineOneY;
  int lineTwoY;
  int squareLeftX;
  int squareRightX;
}squareDef;

typedef struct {
  int ZLeftTwoX;
  int ZLeftX;
  int ZMiddleX;
  int ZRightX;
  int ZRightTwoX;
  int lineOneY;
  int lineTwoY;
  int lineThreeY;
}ZDef;

typedef struct {
  int LLeftX;
  int LMiddleX;
  int LRightX;
  int lineOneY;
  int lineTwoY;
  int lineThreeY;
}LDef;

typedef struct {
  int JLeftX;
  int JMiddleX;
  int JRightX;
  int lineOneY;
  int lineTwoY;
  int lineThreeY;
}JDef;

typedef struct {
  int TLeftX;
  int TMiddleX;
  int TRightX;
  int lineOneY;
  int lineTwoY;
  int lineThreeY;
}TDef;

typedef struct {
  int IMiddleX;
  int lineOneY;
  int lineTwoY;
  int lineThreeY;
}IDef;


void errorHandler(int errorCode);
void Affiche(char mat[Y][X]);
void square(char mat[Y][X], int isSet);
void zeee(char mat[Y][X], int isSet);
void leee(char mat[Y][X], int isSet);
void jeee(char mat[Y][X], int isSet);
void teee(char mat[Y][X], int isSet);
void iail(char mat[Y][X], int isSet);
void putBlockInMat(int randomNumber,char mat[Y][X], int isSet);
void blockEnd(char mat[Y][X]);
void initMatrix(char mat[Y][X]);
int randomize();
void matrixMovement(char mat[Y][X], int typeOfBlock);
