#include "Matrix.h"

int main() {
    int aNums[] = {6, 4, 8, 3};
    Matrix A = Matrix(2, 2, aNums, 4);
    int bNums[] = {1, 2, 3, 4, 5, 6};
    Matrix B = Matrix(2, 3, bNums, 6);
    int cNums[] = {2, 4, 6, 1, 3, 5};
    Matrix C = Matrix(2, 3, cNums, 6);

    A.print();
    std::cout << std::endl;
    B.print();
    std::cout << std::endl;
    C.print();
    std::cout << std::endl;

    Matrix D = (B.scale(3)).multiply(C.transpose()).add(A);

    D.print();

    return 0;
}