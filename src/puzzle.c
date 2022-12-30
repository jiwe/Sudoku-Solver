#include "sudoku.h"

int ** createPuzzle() {
  int i, j;
  int array[9][9]= {0, 1, 9,      8, 0, 2,     0, 0, 0,
                      4, 7, 0,      6, 9, 0,     0, 0, 1,
                      0, 0, 0,      4, 0, 0,     0, 9, 0,

                      8, 9, 4,      5, 0, 7,     0, 0, 0,
                      0, 0, 0,      0, 0, 0,     0, 0, 0,
                      0, 0, 0,      2, 0, 1,     9, 5, 8,

                      0, 5, 0,      7, 0, 6,     0, 0, 0,
                      6, 0, 0,      3, 2, 8,     0, 7, 9,
                      0, 0, 0,      1, 0, 0,     8, 6, 0 };
  int ** puzzle = (int **)malloc(sizeof(int *) * 9);

  for (i = 0; i < SIZE_ROWS; ++i) {
    puzzle[i] = (int *)malloc(sizeof(int) * 9);
    for (j = 0; j < SIZE_COLUMNS; ++j) {
      puzzle[i][j] = array[i][j];
    }
  }
  return puzzle;
}

void printPuzzle(Square *** sudoku) {
  int i, j;
  printf("-------------------------------\n");
  for (i = 0; i < SIZE_ROWS; ++i) {
    printf("|");
    for (j = 0; j < SIZE_COLUMNS; ++j) {
      printf(" %d ", sudoku[i][j]->number);
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

Square *** setUpPuzzle(int ** puzzle) {
  int i, j, x;
  Square *** sudoku= (Square ***)malloc(sizeof(Square **) * 9);
  Box ** boxes = createBoxes();
  int currentBox = 0;
  
  for (i = 0; i < SIZE_ROWS; ++i) {
    sudoku[i] = (Square **)malloc(sizeof(Square *) * 9);
    for (j = 0; j < SIZE_COLUMNS; ++j) {
      sudoku[i][j] = (Square *)malloc(sizeof(Square));
      sudoku[i][j]->row = i;
      sudoku[i][j]->column = j;
      sudoku[i][j]->number = puzzle[i][j];
      sudoku[i][j]->solvable = 9;

      boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
      sudoku[i][j]->box = boxes[currentBox];
      boxes[currentBox]->numbers++;

      for (x = 0; x < SIZE_ROWS; ++x) {
        sudoku[i][j]->possible[x] = 0;
      }

      if (j == 2)
        currentBox++;
      if (j == 5)
        currentBox++;
    }
    currentBox -= 2;
    if (i == 2)
      currentBox = 3;
    if (i == 5)
      currentBox = 6;
  }

  for (i = 0; i < SIZE_ROWS; ++i) {
    for (j = 0; j < SIZE_COLUMNS; ++j) {
      if (sudoku[i][j]->number != 0) {
        sudoku[i][j]->solvable = 0;
        updateSudoku(sudoku, i ,j);
        updateBoxes(sudoku, i, j);
        --UNSOLVED;
      }
    }
  }

  return sudoku;
}

void updateSudoku(Square *** sudoku, int row, int column) {
  int number = sudoku[row][column]->number;
  for (int i = 0; i < SIZE_COLUMNS; ++i) {
    if (sudoku[row][i]->possible[number-1] == 0) {
      --sudoku[row][i]->solvable;
    }
    sudoku[row][i]->possible[number-1] = 1;
  }

  for (int i = 0; i < SIZE_ROWS; ++i) {
    if (sudoku[i][column]->possible[number-1] == 0) {
      --sudoku[i][column]->solvable;
    }
    sudoku[i][column]->possible[number-1] = 1;
  }
}


void checkPuzzle(Square *** sudoku) {
  for (int i = 0; i < SIZE_ROWS; ++i) {
    for (int j = 0; j < SIZE_COLUMNS; ++j) {
      if (sudoku[i][j]->solvable == 1) {
        solveSquare(sudoku[i][j]);
        updateSudoku(sudoku, i, j);
      }
    }
  }
}
