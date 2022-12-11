#include "sudoku.h"

char POSSIBLE = 0x1FF;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int ** createPuzzle() {
  int i, j;
  int matrix[9][9] = {
    9,2,0, 0,1,0, 3,0,0,
    8,5,0, 0,9,0, 0,2,0,
    0,0,3, 0,0,0, 0,0,0,
    0,0,0, 0,0,2, 0,0,0,
    3,0,0, 0,0,1, 6,0,0,
    1,9,7, 0,0,0, 2,5,0,
    0,0,0, 5,0,9, 0,6,2,
    0,8,5, 0,2,0, 4,0,0,
    0,0,9, 7,4,0, 0,3,0,
  };  

  int ** puzzle = (int **)malloc(sizeof(int *) * 9);

  for (i = 0; i < SIZE_ROWS; ++i) {
    puzzle[i] = (int *)malloc(sizeof(int) * 9);
    for (j = 0; j < SIZE_COLUMNS; ++j) {
      puzzle[i][j] = matrix[i][j];
    }
  }
  return puzzle;
}

void printPuzzle(int ** puzzle) {
  int i, j;
  printf("-------------------------------\n");
  for (i = 0; i < SIZE_ROWS; ++i) {
    printf("|");
    for (j = 0; j < SIZE_COLUMNS; ++j) {
      printf(" %d ", puzzle[i][j]);
      if ((j % 3) == 2) {
        printf("|");
      }
        
    }
    printf("\n");
    if ((i % 3) == 2){
      printf("-------------------------------\n");
    }
  }
}

Square *** setupPuzzle(int ** puzzle) {
  int i, j;
  Square *** sudoku= (Square ***)malloc(sizeof(Square **) * 9);
  for (i = 0; i < SIZE_ROWS; ++i) {
    sudoku[i] = (Square **)malloc(sizeof(Square *) * 9);
    for (j = 0; j < SIZE_COLUMNS; ++j) {
      sudoku[i][j] = (Square *)malloc(sizeof(Square));
      sudoku[i][j]->row = i;
      sudoku[i][j]->col = j;
      sudoku[i][j]->number = puzzle[i][j];
      if (sudoku[i][j]->number != 0) {
        sudoku[i][j]->code = POSSIBLE;
      } else {
        sudoku[i][j]->code = 0x0;
      }
    }
  }
  return sudoku;
}