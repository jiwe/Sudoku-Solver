#include <stdio.h>
#include <stdlib.h>

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