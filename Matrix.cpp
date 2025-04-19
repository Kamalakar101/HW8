#include "Matrix.h"

Matrix::Matrix() {
    m_numRows = 0;
    m_numCols = 0;
    m_matrix = nullptr;
}

Matrix::Matrix(int numRows, int numCols) {
    m_numRows = numRows;
    m_numCols = numCols;
    m_matrix = buildMatrix(numRows, numCols);
}

Matrix::Matrix(int numRows, int numCols, int *nums, int sizeOfNums) {
    m_numRows = numRows;
    m_numCols = numCols;
    m_matrix = buildMatrix(numRows, numCols);
    populate(nums, sizeOfNums);

}

Matrix::~Matrix() {
    clear();
}

Matrix &Matrix::operator=(const Matrix &rhs) {
    // TODO: insert return statement here
}

void Matrix::clear() {
    for (int i = 0; i < m_numRows; i++) {
        delete m_matrix[i];
    }
    delete[] m_matrix;

    m_numRows = 0;
    m_numCols = 0;
    m_matrix = nullptr;
}

int Matrix::getNumRows() {
    return m_numRows;
}

int Matrix::getNumCols() {
    return m_numCols;
}

bool Matrix::populate(int *nums, int sizeOfNums) {
    if (sizeOfNums != (m_numRows * m_numCols)) {
        return false;
    }
    
    int index = 0;
    for (int i = 0; i < m_numRows; i++) {
        index += m_numCols;
        for (int j = 0; j < m_numCols; j++) {
            m_matrix[i][j] = nums[j + index];
        }
    }
}

Matrix Matrix::add(const Matrix &rhs) {

    Matrix newMatrix = Matrix(m_numRows, m_numCols);
    if (m_numCols != rhs.m_numCols || m_numRows != rhs.m_numRows) {
        //Error
    }

    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            newMatrix.m_matrix[i][j] = m_matrix[i][j] + rhs.m_matrix[i][j];
        }
    }

    return newMatrix;
}

Matrix Matrix::scale(int scalar) {
    Matrix newMatrix = Matrix(m_numRows, m_numCols);
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            newMatrix.m_matrix[i][j] = m_matrix[i][j] * scalar;
        }
    }
}

Matrix Matrix::multiply(const Matrix &rhs) {
    if (m_numCols != rhs.m_numRows) {
        //Error
    }
    Matrix newMatrix = Matrix(m_numRows, rhs.m_numCols);

    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < rhs.m_numCols; j++) {
            for (int k = 0; k < m_numCols; k++) {
                newMatrix.m_matrix[i][j] += m_matrix[i][k] * rhs.m_matrix[k][j];
            }
        }
    }

    return newMatrix;
}

Matrix Matrix::transpose() {
    Matrix newMatrix = Matrix(m_numCols, m_numRows);

    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            newMatrix.m_matrix[j][i] = m_matrix[i][j];
        }
    }

    return newMatrix;
}

int ** Matrix::buildMatrix(int numRows, int numCols) {
    int ** matrix = new int*[numRows];
    for (int i = 0; i < m_numRows; i++) {
        matrix[i] = new int[numCols]();
    }
    return matrix;
}
