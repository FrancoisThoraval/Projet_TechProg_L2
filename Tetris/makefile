all : matrixHandler.o movementHandler.o scoreHandler.o kbhit.o main.o
	gcc matrixHandler.o movementHandler.o scoreHandler.o kbhit.o main.o -o Tetris -lncurses
	rm *.o

main.o: main.c
	gcc -Wall -c main.c

matrixHandler.o : matrixHandler.c
	gcc -Wall -c matrixHandler.c

scoreHandler.o : scoreHandler.c
	gcc -Wall -c scoreHandler.c

movementHandler.o : movementHandler.c
	gcc -Wall -c movementHandler.c

kbhit.o : kbhit.c
	gcc -Wall -c kbhit.c
# clean ne s'execute pas tout seul ...
clean:
	rm *.o
