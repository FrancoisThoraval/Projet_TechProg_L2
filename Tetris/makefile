all : matrixHandler.o movementHandler.o scoreHandler.o tetris.o menu.o musicHandler.o main.o
	gcc matrixHandler.o movementHandler.o scoreHandler.o tetris.o menu.o musicHandler.o main.o -o Tetris -lncurses `sdl-config --cflags --libs` -lSDL_mixer
	rm *.o

main.o: main.c
	gcc -Wall -c main.c `sdl-config --cflags --libs`

tetris.o: tetris.c
	gcc -Wall -c tetris.c `sdl-config --cflags --libs`

menu.o: menu.c
		gcc -Wall -c menu.c `sdl-config --cflags --libs`


matrixHandler.o : matrixHandler.c
	gcc -Wall -c matrixHandler.c `sdl-config --cflags --libs`

scoreHandler.o : scoreHandler.c
	gcc -Wall -c scoreHandler.c `sdl-config --cflags --libs`

movementHandler.o : movementHandler.c
	gcc -Wall -c movementHandler.c `sdl-config --cflags --libs`

musicHandler.o : musicHandler.c
	gcc -Wall -c musicHandler.c `sdl-config --libs` -lSDL_mixer

# clean ne s'execute pas tout seul ...
clean:
	rm *.o
