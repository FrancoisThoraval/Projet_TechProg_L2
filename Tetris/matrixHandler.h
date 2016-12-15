#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"
#include "scoreHandler.h"
#include <ncurses.h>

// =======================================================
// Fichier de gestion de la matrice
// =======================================================

// Fonction qui vérifie si la partie est finie
int gameOver(char mat[Y][X],int mode, int difficulty_O_Meter);

// Procedure qui initialise la matrice avec des ' ' (espaces)
void initMatrix(char mat[Y][X]);

// Fonction qui remplit aléatoirement la matrice (mode alternatif)
void fillMatrix(char mat[Y][X], int difficulty_O_Meter);

// Fonction qui tire au sort un nombre entre 0 et nbValues
int randomize(int nbValues);

// Procedure qui affiche la matrice en y ajoutant les bordures et le score
void show(char mat[Y][X],int score, int line, int tries);

// Procedure qui initialise les coordonées du bloc
void initCoordStruct(coordBlock *block);

// Design blocs
void square(char mat[Y][X], coordBlock *block, char blocChar);
void zeee(char mat[Y][X], int position, coordBlock *block, char blocChar);
void leee(char mat[Y][X], int position, coordBlock *block, char blocChar);
void jeee(char mat[Y][X], int position, coordBlock *block, char blocChar);
void teee(char mat[Y][X], int position, coordBlock *block, char blocChar);
void iail(char mat[Y][X], int position, coordBlock *block, char blocChar);
void seee(char mat[Y][X], int position, coordBlock *block, char blocChar);

// Choisis la forme du bloc a placer dans la matrice
void putBlockInMat(int randomNumber,char mat[Y][X], int position, coordBlock *block, char blocChar);

// Fonction qui renvoit une structure de coordonées dans une autre (prédiction du placement)
coordBlock copyBlock(coordBlock *block);

// Procedure qui initialise une nouvelle matrice dans laquelle on va recopier
// le contenu de l'ancienne, et placer le bloc à sa nouvelle coordonée
// Si PREDICTION (voir definition.h) est à 0, on place le même bloc à l'endroit
// où se trouveras le bloc si l'on descend
void matrixMovement(char mat[Y][X], int typeOfBlock, int position, coordBlock *block);

// Procedure qui transforme le bloc joué ('x') en bloc placé ('o').
void blockEnd(char mat[Y][X]);
