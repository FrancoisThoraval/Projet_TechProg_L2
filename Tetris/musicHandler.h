#include "definition.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include <string.h>
#include "matrixHandler.h" //pour randomize(int nbValues)

// =======================================================
// Fichier de gestion du son
// =======================================================

// Joue un son bref
void playSample(int event, Mix_Chunk *sample);

// Joue une musique
// (le mode folie sonore (isCrazyMode) n'a pas été implémenté (crazymusic.mp3 n'existe pas))
void playSound(int isCrazyMode ,Mix_Music *music);

// Baisse le volume sonore puis libère le pointeur.
// si stop = 1, on quitte la SDL.
void stopSound(Mix_Music *music, int stop);
