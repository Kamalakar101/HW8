#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
public:
    Matrix();
    Matrix(int numRows, int numCols);
    Matrix(int numRows, int numCols, int * nums, int sizeOfNums);
    ~Matrix();
    void clear();
    int getNumRows();
    int getNumCols();
    bool populateMatrix(int * nums, int sizeOfNums);
    bool addMatrix(const Matrix& rhs);
    bool scaleMatrix(int scalar);
    bool multiplyMatrix(const Matrix &rhs);
    void transposeMatrix();
private:
    int m_numRows;
    int m_numCols;
    int ** m_matrix;


    int ** buildMatrix(int numRows, int numCols);
};

#endif