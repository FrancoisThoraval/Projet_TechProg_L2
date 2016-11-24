all : matrixHandler.o movementHandler.o scoreHandler.o tetris.o menu.o main.o
	gcc matrixHandler.o movementHandler.o scoreHandler.o tetris.o menu.o main.o -o Tetris -lncurses
	rm *.o

main.o: main.c
	gcc -Wall -c main.c

tetris.o: tetris.c
	gcc -Wall -c tetris.c

menu.o: menu.c
		gcc -Wall -c menu.c


matrixHandler.o : matrixHandler.c
	gcc -Wall -c matrixHandler.c

scoreHandler.o : scoreHandler.c
	gcc -Wall -c scoreHandler.c

movementHandler.o : movementHandler.c
	gcc -Wall -c movementHandler.c

# clean ne s'execute pas tout seul ...
clean:
	rm *.o
