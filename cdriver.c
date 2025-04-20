#include "cmatrix.h"

int main() {
    int aNums[] = {6, 4, 8, 3};
    int ** A = constructPrePopulatedMatrix(2, 2, aNums);
    int bNums[] = {1, 2, 3, 4, 5, 6};
    int ** B = constructPrePopulatedMatrix(2, 3, bNums);
    int cNums[] = {2, 4, 6, 1, 3, 5};
    int ** C = constructPrePopulatedMatrix(2, 3, cNums);

    int ** B_scaled = scale(B, 3, 2, 3);           // 3 * B
    int ** C_T = transpose(C, 2, 3);             // C^T
    int ** product = multiply(B_scaled, C_T, 2, 3, 3, 2); // (3 * B) * C^T
    int ** D = add(A, product, 2, 2);              // A + above result

    printMatrix(D, 2, 2);
    
    freeMatrix(A, 2);
    freeMatrix(B, 2);
    freeMatrix(C, 2);
    freeMatrix(B_scaled, 2);
    freeMatrix(D, 2);


    return 0;
}