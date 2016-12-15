all : matrixHandler.o movementHandler.o scoreHandler.o tetris.o menu.o musicHandler.o main.o
	gcc matrixHandler.o movementHandler.o scoreHandler.o tetris.o menu.o musicHandler.o main.o -o Tetris -lncurses `sdl-config --cflags --libs` -lSDL_mixer
	rm *.o

main.o: main.c
	gcc -Wall -c main.c `sdl-config --cflags --libs` -std=c99

tetris.o: tetris.c
	gcc -Wall -c tetris.c `sdl-config --cflags --libs` -std=c99

menu.o: menu.c
		gcc -Wall -c menu.c `sdl-config --cflags --libs` -std=c99

matrixHandler.o : matrixHandler.c
	gcc -Wall -c matrixHandler.c `sdl-config --cflags --libs` -std=c99

scoreHandler.o : scoreHandler.c
	gcc -Wall -c scoreHandler.c `sdl-config --cflags --libs` -std=c99

movementHandler.o : movementHandler.c
	gcc -Wall -c movementHandler.c `sdl-config --cflags --libs` -std=c99

musicHandler.o : musicHandler.c
	gcc -Wall -c musicHandler.c `sdl-config --libs` -lSDL_mixer -std=c99
