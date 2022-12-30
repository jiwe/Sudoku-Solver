#include "sudoku.h"

void solveSquare(Square *sudoku) {
    for (int i = 0; i < SIZE_ROWS; ++i) {
        if (sudoku->possible[i] == 0) {
            sudoku->number = i + 1;
            sudoku->solvable = 0;
            --UNSOLVED;
        }
    }
}
