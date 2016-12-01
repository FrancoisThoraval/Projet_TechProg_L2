#ifndef definition_h
#define definition_h

#define X 11
#define Y 13
#define lengthName 20
#define nbOldScore 10


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
