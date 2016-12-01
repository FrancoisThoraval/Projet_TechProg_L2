#ifndef definition_h
#define definition_h

#define X 11
#define Y 13
#define lengthName 20
#define nbOldScore 10

// DIFFICULTY
#define CHILL 1
#define EASY 1
#define MEDIUM 1
#define HARD 1
#define PROGAMER 1
#define UNBEARABLE 1

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
  char name[lengthName];
}saveScore;

#endif
