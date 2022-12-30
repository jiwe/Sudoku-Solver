#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Box {
  struct Square ** squares;
  int numbers;
  int possible[9];
  int solvable;
  struct Box *next;
} Box;

typedef struct Square {
  int number;
  int possible[9];
  int solvable;
  int row;
  int column;
  Box * box;
} Square;

int ** createPuzzle();

void printPuzzle(Square *** sudoku);

Square *** setUpPuzzle(int ** puzzle);

void updateSudoku(Square *** sudoku, int row, int column);

void checkPuzzle(Square *** sudoku);

void solveSquare(Square * square);

Box ** createBoxes();

void updateBoxes(Square *** sudoku, int row, int column);

#endif
