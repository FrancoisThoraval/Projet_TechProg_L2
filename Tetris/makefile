all : matrixHandler.o movementHandler.o main.o
	gcc matrixHandler.o movementHandler.o main.o -o Tetris
	rm *.o

main.o: main.c
	gcc -Wall -c main.c

matrixHandler.o : matrixHandler.c
	gcc -Wall -c matrixHandler.c

movementHandler.o : movementHandler.c
	gcc -Wall -c movementHandler.c

# clean ne s'execute pas tout seul ...
clean:
	rm *.o
