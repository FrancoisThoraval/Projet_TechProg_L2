
#include <ncurses.h>			/* ncurses.h includes stdio.h */
#include <string.h>

int main()
{
  initscr();
  keypad(stdscr,TRUE);
  echo();
  char input[20] = "";
  char cur_input;
  printw("Input: ");
  for(int i=0; i <= 20; i++) {
          cur_input = getch();
          if(cur_input != '\n')
                  input[i] = cur_input;
          else
                  break;
  }
  printw("%s\n", input);
  getch();
  endwin();
 return 0;
}
