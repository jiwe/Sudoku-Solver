#include "sudoku.h"

int main(void) {  
  int ** puzzle = createPuzzle();
  printPuzzle(puzzle);
  Square *** sudoku = setupPuzzle(puzzle);
}
