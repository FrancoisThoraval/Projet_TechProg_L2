#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "matrixHandler.h"
#include "movementHandler.h"
#include "scoreHandler.h"
#include "definition.h"
#include "musicHandler.h"
#include <ncurses.h> //Equivalent à conio.h pour kbhit et getch

// Procedure pour jouer au mode classique
void play(float difficulty_O_Meter);

// Procedure pour jouer au mode alternatif
void playModeTwo(float difficulty_O_Meter);
