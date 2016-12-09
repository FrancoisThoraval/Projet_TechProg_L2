#ifndef definition_h
#define definition_h

#define X 11
#define Y 13
#define lengthName 20
#define nbOldScore 10
#define SONGNAME 50

// DIFFICULTY
#define NEWLEVEL 10

#define CHILL 1
#define EASY 2
#define MEDIUM 3
#define HARD 4
#define PROGAMER 5
#define UNBEARABLE 6

typedef struct{
  int leftX;
  int middleX;
  int rightX;
  int lineOneY;
  int lineTwoY;
  int lineThreeY;
  int lineFourY;
}coordBlock;

typedef struct{
  int score;
  int line;
  int tries;
  char name[lengthName];
}saveScore;

#endif
