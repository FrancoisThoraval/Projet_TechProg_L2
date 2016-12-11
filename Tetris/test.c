/* compile with "cc -lcurses filename.c" */
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
void santaIsComing(){
  int row,col;				/* to store the number of rows and */
  getmaxyx(stdscr,row,col);
  for (int i = 0; i < col-75; i++) {
    erase();
    mvprintw((row-5)/2,i,"          __                                                      _.\n");
    mvprintw((row-3)/2,i,"_---_.*~<('===          ,~~,         ,~~,         ,~~,           ,_)\n");
    mvprintw((row-1)/2,i,"(,    \\ (__)=3--__._----_()'4__._----_()'4__._----_()'4__._,____.()'b\n");
    mvprintw(row/2,i,"  \\--------/-\\  ~~(        ) ~~(        ) ~~(        )  ~~:       :'\n");
    mvprintw((row+1)/2,i,"   \\_______|       (,_,,,_)     (,_,,,_)     (,_,,,_)     ;,,,,,,:\n");
    mvprintw((row+2)/2,i,"___I___I___I./     / /  \\ \\     / /  \\ \\     / /  \\ \\     / /  \\ \\\n");
    usleep(5*5*1000);
    refresh();
  }
  getch();
}
int main(){
  int col, row;
  initscr();
  getmaxyx(stdscr,row,col);
  for (int i = row; i > 0; i++) {
    erase();
    mvprintw(i,0,"=====================================================");
    mvprintw(i+1,0," \n\n\n                        TETRIS      \n\n difficulty: 3.00\n");
    mvprintw(i+2,0,"===================================================== \n\n");
    mvprintw(i+3,0,"-----------------------------------------------------\n");
    mvprintw(i+4,0,"-->   PLAY\n");
    mvprintw(i+5,0,"     PLAY MODE 2\n");
    mvprintw(i+6,0,"     OPTIONS\n");
    mvprintw(i+7,0,"     BEST SCORES\n");
    mvprintw(i+8,0,"     BEST SCORES MODE 2\n");
    mvprintw(i+9,0,"     EXIT\n");
    mvprintw(i+10,0,"-----------------------------------------------------\n");
    mvprintw(i+11,0,"Note: Use up arrow and down arrow to move\n");
    mvprintw(i+12,0,"      Backspace to choose\n");
    mvprintw(i+13,0,"      'A' to change music in the menu\n");
    usleep(5*100*1000);
    refresh();
  }
  // santaIsComing();
  getch();
  endwin();
  return 0;
}
