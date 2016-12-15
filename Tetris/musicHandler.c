#include "musicHandler.h"

void playSample(int event, Mix_Chunk *sample){
  Mix_Volume(-1,MIX_MAX_VOLUME);
  switch (event) {
    case 1:
      sample = Mix_LoadWAV("Music&Sounds/HitmarkerSoundEffect.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 2:
      sample = Mix_LoadWAV("Music&Sounds/batman.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 3:
      sample = Mix_LoadWAV("Music&Sounds/cameraShutter.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 4:
      sample = Mix_LoadWAV("Music&Sounds/DamnSon.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 5:
      sample = Mix_LoadWAV("Music&Sounds/Fatality.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 6:
      sample = Mix_LoadWAV("Music&Sounds/awp.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 7:
      sample = Mix_LoadWAV("Music&Sounds/Sparta.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 8:
      sample = Mix_LoadWAV("Music&Sounds/SmokeWeedEveryday.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 9:
      sample = Mix_LoadWAV("Music&Sounds/allahUakbar.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 10:
      sample = Mix_LoadWAV("Music&Sounds/doh.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 11:
      sample = Mix_LoadWAV("Music&Sounds/Wow.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
    case 12:
      sample = Mix_LoadWAV("Music&Sounds/batmanReversed.wav");
      Mix_PlayChannel( -1, sample, 0 );
      break;
  }
}

void playSound(int isCrazyMode, Mix_Music *music){
  int song;
  Mix_VolumeMusic(MIX_MAX_VOLUME);
  if (isCrazyMode) {
    music = Mix_LoadMUS("crazymusic.mp3");
    Mix_FadeInMusic(music,-1,1000);
  }else{
    song = randomize(10)+1;
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
      case 5:
        music = Mix_LoadMUS("Music&Sounds/DoctorP-BigBoss.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 6:
        music = Mix_LoadMUS("Music&Sounds/FluxPavilion-Got2Know.mp3)");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 7:
        music = Mix_LoadMUS("Music&Sounds/FluxPavilion-ICantStop.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 8:
        music = Mix_LoadMUS("Music&Sounds/SlumDogz-IntheHood.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 9:
        music = Mix_LoadMUS("Music&Sounds/FluxPavilion-BassCannon.mp3");
        Mix_FadeInMusic(music, -1, 2000);
        break;
      case 10:
        music = Mix_LoadMUS("Music&Sounds/CookieMonsta-MoshPit.mp3");
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
