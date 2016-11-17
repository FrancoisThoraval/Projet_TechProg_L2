#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"
#include "scoreHandler.h"

/*
Description: (pas à jour)

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

void errorHandler(int errorCode);
int gameOver(char mat[Y][X]);
int randomize();
void initMatrix(char mat[Y][X]);
void show(char mat[Y][X], int score, int line);
void initCoordStruct();

// Design blocs
void square(char mat[Y][X], int isSet, coordBlock *block);
void zeee(char mat[Y][X], int isSet, int position, coordBlock *block);
void leee(char mat[Y][X], int isSet, int position, coordBlock *block);
void jeee(char mat[Y][X], int isSet, int position, coordBlock *block);
void teee(char mat[Y][X], int isSet, int position, coordBlock *block);
void iail(char mat[Y][X], int isSet, int position, coordBlock *block);
void seee(char mat[Y][X], int isSet, int position, coordBlock *block);

void putBlockInMat(int randomNumber,char mat[Y][X], int isSet, int position, coordBlock *block);
void blockEnd(char mat[Y][X]);
void matrixMovement(char mat[Y][X], int typeOfBlock, int position, coordBlock *block);
