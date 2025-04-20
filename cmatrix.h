#ifndef CMATRIX_H
#define CMATRIX_H
#include <stdio.h>
#include <stdlib.h>
// Function declarations
int ** constructMatrix(int rows, int cols);
int ** constructPrePopulatedMatrix(int rows, int cols, int * nums);
void freeMatrix(int ** matrix, int rows);
int ** populate(int ** matrix, int rows, int cols);
int ** add(int ** lhs, int ** rhs, int rows, int cols);
int ** scale(int ** matrix, int scalar, int rows, int cols);
int ** multiply(int **lhs, int **rhs, int rowsL, int colsL, int rowsR, int colsR);
int ** transpose(int ** matrix, int rows, int cols);
void printMatrix(int ** matrix, int rows, int cols);

#endif