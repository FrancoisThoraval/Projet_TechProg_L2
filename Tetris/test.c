/* compile with "cc -lcurses filename.c" */
#include <ncurses.h>
main() {
  printf("%s\n", curses_version());
}
