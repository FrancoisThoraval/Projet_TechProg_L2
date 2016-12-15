#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "tetris.h"
#include "scoreHandler.h"
#include "musicHandler.h"

// =======================================================
// Fichier de gestion du menu
// =======================================================

// Procedure principale qui initialise l'écran ncurses, la musique avec SDL, et le menu principal
void callMenuWithMusic(float *difficulty_O_Meter);

// Procedures qui gèrent l'affichage en fonction des actions de l'utilisateur
void menu(float *difficulty_O_Meter, Mix_Music *menuMusic);
void menuGameOver(float *difficulty_O_Meter ,int *score, int *line, int *tries, int mode);
void menuOptions(float *difficulty_O_Meter, Mix_Music *menuMusic);
void menuGameModeTwo(float *difficulty_O_Meter, Mix_Music *menuMusic);

// Fonctions qui lisent les actions au clavier de l'utilisateur
int menuMovement(int *pitem, float *difficulty_O_Meter, Mix_Music *menuMusic);
int menuGameOverMovement(int *pitem, int *score, int *line, float *difficulty_O_Meter,int *tries, int mode);
int optionsMovement(int *pitem, float *difficulty_O_Meter, Mix_Music *menuMusic);
int menuMovementGameModeTwo(int *pitem, float *difficulty_O_Meter, Mix_Music *menuMusic);

// Procedures qui ne contiennent que de l'affichage
void displayMenu(int i, float *difficulty_O_Meter);
void displayMenuGameOver(int i);
void displayModeTwo(int i);
void displayMenuOptions(int i);
