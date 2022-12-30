#include "sudoku.h"

Box ** createBoxes() {
  Box ** boxes = malloc(sizeof(Box *) * 9);
  for (int i = 0; i < 9; ++i) {
    boxes[i] = malloc(sizeof(Box));
    boxes[i]->squares = malloc(sizeof(Square*)*9);
    boxes[i]->numbers = 0;
    boxes[i]->solvable = 9;
    for (int j = 0; j < 9; ++j) {
      boxes[i]->possible[j] = 0;
    }
  }
  return boxes;
}

void updateBoxes(Square *** sudoku, int row, int column) {
  int number = sudoku[row][column]->number;
  Box * box = sudoku[row][column]->box;

  for (int i = 0; i < 9; ++i) {
    if (box->squares[i]->possible[number-1] == 0) {
      box->squares[i]->solvable--;
      box->squares[i]->possible[number-1] = 1;
    }
  }
}