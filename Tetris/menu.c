// // Test pour faire un menu en ncurses
// #include <ncurses.h>
// #include <menu.h>
// #include <stdlib.h>
//
// // #define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
// // #define CTRLD 	4
// //
// // char *choices[] = {
// //                         "Choice 1",
// //                         "Choice 2",
// //                         "Choice 3",
// //                         "Choice 4",
// //                         "Exit",
// //                   };
// //
// // int main()
// // {	ITEM **my_items;
// // 	int c;
// // 	MENU *my_menu;
// // 	int n_choices, i;
// // 	ITEM *cur_item;
// //
// //
// // 	initscr();
// // 	cbreak();
// // 	noecho();
// // 	keypad(stdscr, TRUE);
// //
// // 	n_choices = ARRAY_SIZE(choices);
// // 	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
// //
// // 	for(i = 0; i < n_choices; ++i)
// // 	        my_items[i] = new_item(choices[i], choices[i]);
// // 	my_items[n_choices] = (ITEM *)NULL;
// //
// // 	my_menu = new_menu((ITEM **)my_items);
// // 	mvprintw(LINES - 2, 0, "F1 to Exit");
// // 	post_menu(my_menu);
// // 	refresh();
// //
// // 	while((c = getch()) != KEY_F(1))
// // 	{   switch(c)
// // 	    {	case KEY_DOWN:
// // 		        menu_driver(my_menu, REQ_DOWN_ITEM);
// // 				break;
// // 			case KEY_UP:
// // 				menu_driver(my_menu, REQ_UP_ITEM);
// // 				break;
// // 		}
// // 	}
// //
// // 	free_item(my_items[0]);
// // 	free_item(my_items[1]);
// // 	free_menu(my_menu);
// // 	endwin();
// // }
//
//
// // test timeout
// int main() {
//   int ch;
//   int i;
//   int nextMovement;
//   initscr();
//   nodelay(stdscr, TRUE);
//
//   while (i != 5) {
//     ch = getch();
//     switch (ch) {
//       case KEY_LEFT: nextMovement = 1;
//         printf("A gauche \n\n");
//         break;
//       case KEY_DOWN: nextMovement = 2;
//         printf("En bas\n\n");
//         break;
//       case KEY_RIGHT: nextMovement = 3;
//         printf("A droite\n\n");
//         break;
//       case KEY_UP: nextMovement = 4;
//         break;
//       case 'W':;
//       case 'w': nextMovement = 5;
//         break;
//       case 'X':;
//       case 'x': nextMovement = 6;
//         break;
//       case 'P':;
//       case 'p': nextMovement = 7;
//         break;
//       case -1:; //retour de getch quand on a rien tapé
//         break;
//       }
//     printf("Got %d\n",nextMovement);
//     timeout(1000);
//     printf("%d secondes sont passées \n",i+1);
//     i++;
//     endwin();
//   }
//
//
//   return 0;
// }
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char** argv) {
    struct timeval tvalBefore, tvalAfter;  // removed comma

    gettimeofday (&tvalBefore, NULL);
    int i =0;
    while ( i < 10000) {
      printf("test: %f\n",tvalBefore.tv_usec );
      i ++;
    }
    //
    // gettimeofday (&tvalAfter, NULL);
    //
    // // Changed format to long int (%ld), changed time calculation
    //
    // printf("Time in microseconds: %ld microseconds\n",
    //         ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
    //        +tvalAfter.tv_usec) - tvalBefore.tv_usec
    //       ); // Added semicolon
    return 0;
}
