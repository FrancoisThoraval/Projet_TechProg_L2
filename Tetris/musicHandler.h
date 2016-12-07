#include "definition.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include <string.h>
#include "matrixHandler.h"

void playSound(char type, int event, Mix_Music *music);
void stopSound(Mix_Music *music, int stop);
