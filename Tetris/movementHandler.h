#include "matrixHandler.h"
#include "definition.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <sys/time.h>
#include "musicHandler.h"

// =======================================================
// Fichier de Gestion des mouvements
// =======================================================

// Fonctions qui gèrent si on peut faire un mouvement ou non
//  - canRotate -> renvoie une valeur > 0 si on ne peut pas faire pivoter
//  - canMoveV  -> renvoie une valeur > 0 si on ne peut pas faire descendre le bloc
//  - canMoveH  -> renvoie une valeur > 0 si on ne peut pas faire bouger le bloc horizontalement
int canRotate(int direction, coordBlock *block, int typeOfBlock, int *position, char mat[Y][X]);
int canMoveV(char mat[Y][X], coordBlock *block);
int canMoveH(char mat[Y][X], int side, coordBlock *block);

// Fonction qui renvoie la valeur de la touche tapée par l'utilisateur
int getNextMovement(char mat[Y][X],int score, int line);

// Procedures qui s'occupent de modifier les coordonées du bloc dans la matrice.
// - moveLeft -> déplace le bloc de 1 à gauche
// - moveRight -> déplace le bloc de 1 à droite
// - moveDown -> déplace le bloc de 1 en bas
// - directDown -> déplace le bloc jusqu'en bas de la matrice ou jusqu'à rencontrer un bloc déjà placé
void moveDown(coordBlock *block);
void moveRight(char mat[Y][X], coordBlock *block);
void moveLeft(char mat[Y][X], coordBlock *block);
void directDown(char mat[Y][X], int typeOfBlock, int position, coordBlock *block);

// Procedure qui réalise l'action demandée par l'utilisateur
void Move(char mat[Y][X], int movement, int typeOfBlock,int *position, int *score, coordBlock *block);

// Procedure principale des mouvements
// C'est ici qu'on mesure le temps, vérifie si le bloc est placé, et appelle la vérification de la matrice pour les lignes
void movementHandler(char mat[Y][X],int randomNumber,int *score, int *line, coordBlock *block, float seconds, int level, int tries);
