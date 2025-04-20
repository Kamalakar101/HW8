#include "cmatrix.h"

int **constructMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

int **constructPrePopulatedMatrix(int rows, int cols, int * nums) {
    int **matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = nums[index++];
        }
    }

    return matrix;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int **add(int **lhs, int **rhs, int rows, int cols) {
    int ** sum = constructMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = lhs[i][j] + rhs[i][j];
        }
    }
    return sum;
}

int **scale(int ** matrix, int scalar, int rows, int cols) {
    int ** scaled = constructMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scaled[i][j] = matrix[i][j] * scalar;
        }
    }

    return scaled;
}

int **multiply(int **lhs, int **rhs, int rowsL, int colsL, int rowsR, int colsR) {
    int ** product = constructMatrix(rowsL, colsR);
    for (int i = 0; i < rowsL; i++) {
        for (int j = 0; j < colsR; j++) {
            for (int k = 0; k < colsL; k++) {
                product[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }

    return product;
}

int **transpose(int ** matrix, int rows, int cols) {
    int ** newMatrix = constructMatrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix[j][i] = matrix[i][j];
        }
    }

    return newMatrix;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}