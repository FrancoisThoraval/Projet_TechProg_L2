#include "musicHandler.h"

void playSound(char type, int event, Mix_Music *music){
  int song;

  if (type == 'm') {
    song = randomize(4)+1;
    switch (song) {
      case 1:
        music = Mix_LoadMUS("Music&Sounds/DoctorP-FlyingSpaghettiMonster.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 2:
        music = Mix_LoadMUS("Music&Sounds/DoctorP-Tetris.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 3:
        music = Mix_LoadMUS("Music&Sounds/DoctorP-Gorillas.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 4:
        music = Mix_LoadMUS("Music&Sounds/DoctorP-Shishkabob.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
    }
  }
  if (type =='s') {
    // En fonction de l'event on joue un son approprié
    switch (event) {
      case 1:
        music = Mix_LoadMUS("Music&Sounds/HitmarkerSoundEffect.mp3");
        Mix_PlayMusic(music,1);
        break;
    }
  }
  if (type == 'r') {
    song = randomize(6)+1;
    switch (song) {
      case 1:
        music = Mix_LoadMUS("Music&Sounds/CM139_Loop05(90BPM).mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 2:
        music = Mix_LoadMUS("Music&Sounds/CM139_Loop06(130BPM).mp3)");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 3:
        music = Mix_LoadMUS("Music&Sounds/CM139_Loop10_130BPM.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 4:
        music = Mix_LoadMUS("Music&Sounds/CM139_Loop20_130BPM.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 5:
        music = Mix_LoadMUS("Music&Sounds/CM139_Loop27_130BPM.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 6:
        music = Mix_LoadMUS("Music&Sounds/CM139_Loop36_130BPM.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
    }
  }
}

void stopSound(Mix_Music *music, int stop){
  Mix_FadeOutMusic(1000);
  free(music);
  if (stop == 1) {
    SDL_Quit();
  }
}
