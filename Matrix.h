#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>

class Matrix{
public:
    Matrix();
    Matrix(int numRows, int numCols);
    Matrix(int numRows, int numCols, int * nums, int sizeOfNums);
    ~Matrix();
    Matrix& operator=(const Matrix& rhs);
    Matrix(const Matrix& other);

    void clear();
    int getNumRows();
    int getNumCols();
    bool populate(int * nums, int sizeOfNums);
    Matrix add(const Matrix& rhs);
    Matrix scale(int scalar);
    Matrix multiply(const Matrix &rhs);
    Matrix transpose();
    void print() const;
private:
    int m_numRows;
    int m_numCols;
    int ** m_matrix;


    int ** buildMatrix(int numRows, int numCols);
};

#endif