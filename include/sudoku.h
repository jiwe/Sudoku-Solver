#include <stdio.h>
#include <stdlib.h>

extern char POSSIBLE;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Box {
  struct Box *next;
} Box;

typedef struct Square {
  int number;
  char code;
  int row;
  int col;
  Box * box;
} Square;

int ** createPuzzle();

void printPuzzle(int ** puzzle);

Square *** setupPuzzle(int ** puzzle);