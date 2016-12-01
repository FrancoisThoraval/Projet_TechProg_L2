#include "menu.h"
#include "definition.h"
#include "scoreHandler.h"

void displayMenu(int i){
  switch (i) {
    case 1:
      erase();
      printw("-----------------------------------------------------\n");
      printw("-->  PLAY\n");
      printw("     OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 2:
      erase();
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("-->  OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 3:
      erase();
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("     OPTIONS\n");
      printw("-->  BEST SCORES\n");
      printw("     EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
    case 4:
      erase();
      printw("-----------------------------------------------------\n");
      printw("     PLAY\n");
      printw("     OPTIONS\n");
      printw("     BEST SCORES\n");
      printw("-->  EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
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
      printw("-->  SAVE YOUR SCORE\n");
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
      printw("-->  BACK TO MENU\n");
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
      printw("-->  EXIT\n");
      printw("-----------------------------------------------------\n");
      printw("Note: Use up arrow and down arrow to move\n");
      printw("      Backspace to choose\n");
      break;
  }
}

int menuMovement(int *pitem){

  saveScore oldScores[nbOldScore];
  int nextMovement= 0;
  int input;
  int somethingNice;
  keypad(stdscr, TRUE);
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  input = getch();
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
        case 1: play();
          printw("Playing !\n");
          break;
        case 2: /*options();*/
          printw("Options !\n");
          break;
        case 3: /*bestScores()*/
          erase();
          endwin();
          system("clear");
          fileScoreHandler(oldScores,0);
          printBestScores(oldScores);
          printf("\n -------- type something to go back to menu --------\n");
          scanf("%d\n",&somethingNice );
          menu();
          break;
        case 4:
          printw("Leaving !\n");
          endwin();
          system("clear");
          exit(0);
          break;
      }
      break;

    case -1:; //retour de getch quand on a rien tapé
      break;

    default: printw("touche non définie\n");
      nextMovement = menuMovement(pitem);
  }
  return nextMovement;
}

int menuGameOverMovement(int *pitem, int *score, int *line){

  int nextMovement= 0;
  int input;
  keypad(stdscr, TRUE);
  noecho();  // pressed symbols wont be printed to screen
  cbreak();  // disable line buffering
  input = getch();
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
          endwin();
          Score(score,line);
          break;
        case 2: menu();
          break;
        case 3:
          printw("Leaving !\n");
          endwin();
          system("clear");
          exit(0);
          break;
      }
      break;

    case -1:; //retour de getch quand on a rien tapé
      break;

    default: printw("touche non définie\n");
      nextMovement = menuGameOverMovement(pitem, score, line);
  }
  return nextMovement;
}

void menuGameOver(int *score, int *line){
  int item = 1;
  int input;
  erase();
  noecho();
  displayMenuGameOver(item);
  refresh();
  input = menuGameOverMovement(&item, score, line);
  while (input != KEY_BACKSPACE) {
    displayMenuGameOver(item);
    input = menuGameOverMovement(&item, score, line);
    refresh();
  }
}

void menu(){
  int item = 1;
  int input;
  initscr();
  erase();
  noecho();
  displayMenu(item);
  refresh();
  input = menuMovement(&item);
  while (input != KEY_BACKSPACE) {
    displayMenu(item);
    input = menuMovement(&item);
    refresh();
  }
  endwin();
}
