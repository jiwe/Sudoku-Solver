#include "sudoku.h"

int ** createPuzzle() {
  int i, j;
  int matrix[9][9] = {
    {9,2,0, 0,1,0, 3,0,0},
    {8,5,0, 0,9,0, 0,2,0},
    {0,0,3, 0,0,0, 0,0,0},
    {0,0,0, 0,0,2, 0,0,0},
    {3,0,0, 0,0,1, 6,0,0},
    {1,9,7, 0,0,0, 2,5,0},
    {0,0,0, 5,0,9, 0,6,2},
    {0,8,5, 0,2,0, 4,0,0},
    {0,0,9, 7,4,0, 0,3,0}
  };  
  int ** puzzle = (int **)malloc(sizeof(int *) * 9);
  for (i = 0; i < 9; ++i) {
    puzzle[i] = (int *)malloc(sizeof(int) * 9);
    for (j = 0; j < 9; ++j) {
      puzzle[i][j] = matrix[i][j];
    }
  }
  return puzzle;
}

void printPuzzle(int ** puzzle) {
  int i, j;
  printf("----------------------------\n");
  for (i = 0; i < 9; ++i) {
    printf("| ");
    for (j = 0; j < 9; ++j) {
      printf("%d| ", puzzle[i][j]);
    }
    printf("\n----------------------------\n");
  }
}
