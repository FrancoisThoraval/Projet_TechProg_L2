#include "definition.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

// =======================================================
// Fichier de gestion du score
// =======================================================

// Note: toutes les Fonctions/Procedures avec "2" correspondent
//       au mode alternatif.

// Procedure qui affiche le score
void showScore(int score, int line, int tries);

// Procedures qui affichent les meilleurs scores
void printBestScores(saveScore oldScores[nbOldScore]);
void printBestScores2(saveScore oldScores[nbOldScore]);

// Procedure qui saisit un nom d'utilisateur dans un tableau de caractères
void getName(char name[lengthName]);

// Procedures de gestion des fichiers
// readFile   -> Lit un fichier contenant le score (score.txt et score2.txt)
// writeFile  -> Ecrit dans le fichier lu le nouveau score
// fileScoreHandler -> Procedure pour choisir ce qu'on veut faire et qui appelle readFile et writeFile
void readFile(saveScore oldScores[nbOldScore]);
void readFile2(saveScore oldScores[nbOldScore]);
void writeFile(saveScore oldScores[nbOldScore]);
void writeFile2(saveScore oldScores[nbOldScore]);
void fileScoreHandler(saveScore oldScores[nbOldScore], int intention);

// Procedures de tri du score
// ramScores -> Echange des scores pour le tri
// sortScores  -> Tri en fonction des points
// sortScores2 -> Tri en fonction des tentatives
void ramScores(saveScore *oldScores, saveScore *save, int isMode2);
void sortScores(saveScore oldScores[nbOldScore], saveScore save);
void sortScores2(saveScore oldScores[nbOldScore], saveScore save);

// Procedures qui dirigent l'ordre dans lequel on gère les fichiers
void Score(int *score, int *line, float *difficulty_O_Meter);
void Score2(int *score, int *line, float *difficulty_O_Meter, int *tries);

// Procedure qui supprime une ligne donnée dans la matrice
void deleteLine(char mat[Y][X], int line);

// Procedure qui parcours la matrice pour savoir s'il y a une ligne plein ou non
// Si ligne pleine on la supprime avec deleteLine.
void checkLines(char mat[Y][X], int *score, int *line, int level);
