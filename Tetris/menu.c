#include "menu.h"
#include "definition.h"
#include "scoreHandler.h"

void menuOptions(float *difficulty_O_Meter, Mix_Music *menuMusic);

void displayMenu(int i, float *difficulty_O_Meter){
  switch (i) {
    case 1:
      erase();
      printw("=====================================================");
      printw(" \n\n\n                        TETRIS      \n\n difficulty: %.2f\n", *difficulty_O_Meter);
      printw("===================================================== \n\n");
      printw("-----------------------------------------------------\n");
      printw("-->   PLAY\n");
      printw("     PLAY MODE 2\n");
      printw("     OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("     BEST SCORES MODE 2\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      printw("      'A' to change music in the menu\n");
      break;
    case 2:
      erase();
      printw("=====================================================");
      printw(" \n\n\n                        TETRIS      \n\n difficulty: %.2f\n", *difficulty_O_Meter);
      printw("===================================================== \n\n");
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("-->   PLAY MODE 2\n");
      printw("     OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("     BEST SCORES MODE 2\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      printw("      'A' to change music in the menu\n");
      break;
    case 3:
      erase();
      printw("=====================================================");
      printw(" \n\n\n                        TETRIS      \n\n difficulty: %.2f\n", *difficulty_O_Meter);
      printw("===================================================== \n\n");
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("     PLAY MODE 2\n");
      printw("-->   OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("     BEST SCORES MODE 2\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      printw("      'A' to change music in the menu\n");
      break;
    case 4:
      erase();
      printw("=====================================================");
      printw(" \n\n\n                        TETRIS      \n\n difficulty: %.2f\n", *difficulty_O_Meter);
      printw("===================================================== \n\n");
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("     PLAY MODE 2\n");
      printw("     OPTIONS\n");
      printw("-->   BEST SCORES\n");
      printw("     BEST SCORES MODE 2\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      printw("      'A' to change music in the menu\n");
      break;
    case 5:
      erase();
      printw("=====================================================");
      printw(" \n\n\n                        TETRIS      \n\n difficulty: %.2f\n", *difficulty_O_Meter);
      printw("===================================================== \n\n");
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("     PLAY MODE 2\n");
      printw("     OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("-->   BEST SCORES MODE 2\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      printw("      'A' to change music in the menu\n");
      break;
    case 6:
      erase();
      printw("=====================================================");
      printw(" \n\n\n                        TETRIS      \n\n difficulty: %.2f\n", *difficulty_O_Meter);
      printw("===================================================== \n\n");
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("     PLAY MODE 2\n");
      printw("     OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("     BEST SCORES MODE 2\n");
      printw("-->   EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      printw("      'A' to change music in the menu\n");
      break;
  }
}

void displayMenuGameOver(int i){
  switch (i) {
    case 1:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                    !!! GAME OVER !!!\n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("-->   SAVE YOUR SCORE\n");
      printw("     BACK TO MENU\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 2:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                    !!! GAME OVER !!!\n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     SAVE YOUR SCORE\n");
      printw("-->   BACK TO MENU\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 3:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                    !!! GAME OVER !!!\n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     SAVE YOUR SCORE\n");
      printw("     BACK TO MENU\n");
      printw("-->   EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
  }
}

void displayModeTwo(int i){
  switch (i) {
    case 1:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                    Choose Level \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("-->   Level 1 (4 lines)\n");
      printw("     Level 2 (6 lines)\n");
      printw("     Level 3 (8 lines)\n");
      printw("     Back to menu\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 2:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                    Choose Level \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     Level 1 (4 lines)\n");
      printw("-->   Level 2 (6 lines)\n");
      printw("     Level 3 (8 lines)\n");
      printw("     Back to menu\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 3:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                    Choose Level \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     Level 1 (4 lines)\n");
      printw("     Level 2 (6 lines)\n");
      printw("-->   Level 3 (8 lines)\n");
      printw("     Back to menu\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 4:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                    Choose Level \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     Level 1 (4 lines)\n");
      printw("     Level 2 (6 lines)\n");
      printw("     Level 3 (8 lines)\n");
      printw("-->   Back to menu\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
  }
}

void displayMenuOptions(int i){
  switch (i) {
    case 1:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                        OPTIONS       \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("-->   CHILL (CONSTANT SPEED)\n");
      printw("     EASY\n");
      printw("     MEDIUM (DEFAULT)\n");
      printw("     HARD\n");
      printw("     PRO GAMER\n");
      printw("     UNBEARABLE\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      refresh();
      break;
    case 2:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                        OPTIONS       \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     CHILL (CONSTANT SPEED)\n");
      printw("-->   EASY\n");
      printw("     MEDIUM (DEFAULT)\n");
      printw("     HARD\n");
      printw("     PRO GAMER\n");
      printw("     UNBEARABLE\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      refresh();
      break;
    case 3:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                        OPTIONS       \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     CHILL (CONSTANT SPEED)\n");
      printw("     EASY\n");
      printw("-->   MEDIUM (DEFAULT)\n");
      printw("     HARD\n");
      printw("     PRO GAMER\n");
      printw("     UNBEARABLE\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      refresh();
      break;
    case 4:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                        OPTIONS       \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     CHILL (CONSTANT SPEED)\n");
      printw("     EASY\n");
      printw("     MEDIUM (DEFAULT)\n");
      printw("--->  HARD\n");
      printw("     PRO GAMER\n");
      printw("     UNBEARABLE\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      refresh();
      break;
    case 5:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                        OPTIONS       \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     CHILL (CONSTANT SPEED)\n");
      printw("     EASY\n");
      printw("     MEDIUM (DEFAULT)\n");
      printw("     HARD\n");
      printw("-->   PRO GAMER\n");
      printw("     UNBEARABLE\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      refresh();
      break;
    case 6:
      erase();
      printw("=======================================================================");
      printw(" \n\n\n                        OPTIONS       \n\n\n");
      printw("======================================================================= \n\n");
      printw("-----------------------------------------------------\n");
      printw("     CHILL (CONSTANT SPEED)\n");
      printw("     EASY\n");
      printw("     MEDIUM (DEFAULT)\n");
      printw("     HARD\n");
      printw("     PRO GAMER\n");
      printw("-->   UNBEARABLE\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      refresh();
      break;
  }
}

int optionsMovement(int *pitem, float *difficulty_O_Meter, Mix_Music *menuMusic){
  Mix_Chunk *sample = NULL;
  int nextMovement= 0;
  int input;
  keypad(stdscr, TRUE);
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  do{
    input = getch();
  }while(input == ERR);
  nocbreak();
  switch (input) {
    case KEY_UP: nextMovement = 1;
      *pitem = *pitem-1;
      if (*pitem == 0) {
        *pitem = 6;
      }
      break;
    case KEY_DOWN: nextMovement = 2;
      *pitem = *pitem+1;
      if (*pitem == 7) {
        *pitem = 1;
      }
      break;
    case KEY_BACKSPACE: nextMovement = 3;
      switch (*pitem) {
        case 1:
          *difficulty_O_Meter = CHILL;
          printw("diff: %f", *difficulty_O_Meter);
          refresh();
          playSample(12,sample);
          menu(difficulty_O_Meter, menuMusic);
          break;
        case 2:
          *difficulty_O_Meter = EASY;
          printw("diff: %f", *difficulty_O_Meter);
          refresh();
          playSample(12,sample);
          menu(difficulty_O_Meter, menuMusic);
          break;
        case 3:
          *difficulty_O_Meter = MEDIUM;
          printw("diff: %f", *difficulty_O_Meter);
          refresh();
          playSample(12,sample);
          menu(difficulty_O_Meter, menuMusic);
          break;
        case 4:
          *difficulty_O_Meter = HARD;
          printw("diff: %f", *difficulty_O_Meter);
          refresh();
          playSample(12,sample);
          menu(difficulty_O_Meter, menuMusic);
          break;
        case 5:
          *difficulty_O_Meter = PROGAMER;
          printw("diff: %f", *difficulty_O_Meter);
          refresh();
          playSample(12,sample);
          menu(difficulty_O_Meter, menuMusic);
          break;
        case 6:
          *difficulty_O_Meter = UNBEARABLE;
          printw("diff: %f\n", *difficulty_O_Meter);
          refresh();
          playSample(12,sample);
          menu(difficulty_O_Meter, menuMusic);
          break;
      }
      break;

    case -1:; //retour de getch quand on a rien tapé
      break;

    default: playSample(10,sample);
      nextMovement = optionsMovement(pitem, difficulty_O_Meter, menuMusic);
  }
  free(sample);
  return nextMovement;
}

int menuMovement(int *pitem, float *difficulty_O_Meter, Mix_Music *menuMusic){
  Mix_Chunk *sample = NULL;
  saveScore oldScores[nbOldScore];
  int nextMovement= 0;
  int input;
  int somethingNice;
  keypad(stdscr, TRUE);
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  // while((input=getchar())!= '\n' && input!= EOF);
  do{
    input = getch();
  }while(input == ERR);
  nocbreak();
  switch (input) {
    case 'a':
    case 'A': playSound(0,menuMusic);
      break;
    case KEY_UP: nextMovement = 1;
      *pitem = *pitem-1;
      if (*pitem == 0) {
        *pitem = 6;
      }
      break;
    case KEY_DOWN: nextMovement = 2;
      *pitem = *pitem+1;
      if (*pitem == 7) {
        *pitem = 1;
      }
      break;
    case KEY_BACKSPACE: nextMovement = 3;
      switch (*pitem) {
        case 1:
          Mix_FadeOutMusic(1000);
          free(menuMusic);
          Mix_CloseAudio();
          play(*difficulty_O_Meter);
          printw("Playing !\n");
          break;
        case 2:
          playSample(2,sample);
          menuGameModeTwo(difficulty_O_Meter,menuMusic);
        case 3: /*options();*/
          printw("Options !\n");
          playSample(2,sample);
          menuOptions(difficulty_O_Meter, menuMusic);
          break;
        case 4: /*bestScores()*/
          erase();
          fileScoreHandler(oldScores,0);
          playSample(3,sample);
          printBestScores(oldScores);
          printw("\n -------- type ENTER to go back to menu --------\n");
          do {
            somethingNice = getch();
          } while(somethingNice != 10); //Il faut appuyer sur entrée pour quitter
          menu(difficulty_O_Meter, menuMusic);
          break;
        case 5: /*bestScores()*/
          erase();
          endwin();
          // system("clear");
          fileScoreHandler(oldScores,2);
          playSample(3,sample);
          printBestScores2(oldScores);
          printw("\n -------- type ENTER to go back to menu --------\n");
          do {
            somethingNice = getch();
          } while(somethingNice != 10); //Il faut appuyer sur entrée pour quittero back to menu --------\n");
          scanw("%d\n",&somethingNice );
          menu(difficulty_O_Meter, menuMusic);
          break;
        case 6:
          printw("Leaving !\n");
          refresh();
          playSample(7,sample);
          stopSound(menuMusic,0);
          usleep(3900*1000);
          stopSound(menuMusic,1);
          endwin();
          system("clear");
          exit(0);
          break;
      }
      break;

    default: playSample(10,sample);
      printf("inputRecursif: %d\n",input );
      nextMovement = menuMovement(pitem, difficulty_O_Meter, menuMusic);
  }
  free(sample);
  return nextMovement;
}

int menuGameOverMovement(int *pitem, int *score, int *line, float *difficulty_O_Meter, int *tries, int mode){
  Mix_Chunk *sample = NULL;
  int nextMovement= 0;
  int input;
  keypad(stdscr, TRUE);
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  do {
    input = getch();
  } while(input == ERR);
  nocbreak();
  switch (input) {
    case KEY_UP: nextMovement = 1;
      *pitem = *pitem-1;
      if (*pitem == 0) {
        *pitem = 4;
      }
      break;
    case KEY_DOWN: nextMovement = 2;
      *pitem = *pitem+1;
      if (*pitem == 5) {
        *pitem = 1;
      }
      break;
    case KEY_BACKSPACE: nextMovement = 3;
      switch (*pitem) {
        case 1:
          erase();
          // endwin();
          playSample(3,sample);
          if (mode == 1) {
            Score(score,line,difficulty_O_Meter);
          }else
            Score2(score,line,difficulty_O_Meter,tries);
          break;
        case 2:
          printw("press ENTER to confirm\n");
          do {
            input = getch();
          } while(input != 10); //Il faut appuyer sur entrée pour quitter
          playSample(12,sample);
          refresh();
          callMenuWithMusic(difficulty_O_Meter);
          break;
        case 3:
          printw("Leaving !\n");
          refresh();
          playSample(7,sample);
          usleep(3900*1000);
          SDL_Quit();
          printw("Leaving !\n");
          endwin();
          system("clear");
          exit(0);
          break;
      }
      break;

    default: playSample(10,sample);
      nextMovement = menuGameOverMovement(pitem, score, line, difficulty_O_Meter, tries, mode);
  }
  free(sample);
  return nextMovement;
}

int menuMovementGameModeTwo(int *pitem, float *difficulty_O_Meter, Mix_Music *menuMusic){
  Mix_Chunk *sample = NULL;
  int nextMovement= 0;
  int input;
  keypad(stdscr, TRUE);
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  do{
    input = getch();
  }while(input == ERR);
  nocbreak();
  switch (input) {
    case KEY_UP: nextMovement = 1;
      *pitem = *pitem-1;
      if (*pitem == 0) {
        *pitem = 4;
      }
      break;
    case KEY_DOWN: nextMovement = 2;
      *pitem = *pitem+1;
      if (*pitem == 5) {
        *pitem = 1;
      }
      break;
    case KEY_BACKSPACE: nextMovement = 3;
      switch (*pitem) {
        case 1:
          Mix_FadeOutMusic(1000);
          free(menuMusic);
          Mix_CloseAudio();
          playModeTwo(4);
          printw("Playing !\n");
          break;
        case 2: /*options();*/
          Mix_FadeOutMusic(1000);
          free(menuMusic);
          Mix_CloseAudio();
          playModeTwo(6);
          printw("Playing !\n");
          break;
        case 3: /*bestScores()*/
          Mix_FadeOutMusic(1000);
          free(menuMusic);
          Mix_CloseAudio();
          playModeTwo(8);
          printw("Playing !\n");
          break;
        case 4:
          playSample(12,sample);
          menu(difficulty_O_Meter, menuMusic);
          break;
      }
      break;

    default: playSample(10,sample);
      nextMovement = menuMovement(pitem, difficulty_O_Meter, menuMusic);
  }
  free(sample);
  return nextMovement;
}

void menuGameOver(float *difficulty_O_Meter, int *score, int *line, int *tries, int mode){
  int item = 1;
  int input;
  erase();
  noecho();
  displayMenuGameOver(item);
  refresh();
  input = menuGameOverMovement(&item, score, line, difficulty_O_Meter, tries, mode);
  while (input != KEY_BACKSPACE) {
    displayMenuGameOver(item);
    input = menuGameOverMovement(&item, score, line, difficulty_O_Meter, tries, mode);
    refresh();
  }
}

void menuOptions(float *difficulty_O_Meter, Mix_Music *menuMusic){
  int item = 1;
  int input;
  erase();
  noecho();
  displayMenuOptions(item);
  refresh();
  input = optionsMovement(&item, difficulty_O_Meter, menuMusic);
  while (input != KEY_BACKSPACE) {
    displayMenuOptions(item);
    input = optionsMovement(&item, difficulty_O_Meter, menuMusic);
    refresh();
  }
}

void menuGameModeTwo(float *difficulty_O_Meter, Mix_Music *menuMusic){
  int item = 1;
  int input;

  erase();
  noecho();
  displayModeTwo(item);
  refresh();
  input = menuMovementGameModeTwo(&item, difficulty_O_Meter, menuMusic);
  while (input != KEY_BACKSPACE) {
    displayModeTwo(item);
    input = menuMovementGameModeTwo(&item, difficulty_O_Meter, menuMusic);
    refresh();
  }
}

void menu(float *difficulty_O_Meter, Mix_Music *menuMusic){
  int item = 1;
  int input;

  erase();
  noecho();
  displayMenu(item, difficulty_O_Meter);
  refresh();
  input = menuMovement(&item, difficulty_O_Meter, menuMusic);
  while (input != KEY_BACKSPACE) {
    displayMenu(item,difficulty_O_Meter);
    input = menuMovement(&item, difficulty_O_Meter, menuMusic);
    refresh();
  }
  endwin();
}

void callMenuWithMusic(float *difficulty_O_Meter){
  SDL_Init(SDL_INIT_AUDIO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Music *menuMusic = NULL;

  initscr();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);

  attron(COLOR_PAIR(7));
  playSound(0,menuMusic);
  menu(difficulty_O_Meter,menuMusic);

}
