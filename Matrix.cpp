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
    populateMatrix(nums, sizeOfNums);

}

Matrix::~Matrix() {
    clear();
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

bool Matrix::populateMatrix(int *nums, int sizeOfNums) {
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

bool Matrix::addMatrix(const Matrix &rhs)
{
    if (m_numCols != rhs.m_numCols && m_numRows != rhs.m_numRows) {
        return false;
    }

    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            m_matrix[i][j] += rhs.m_matrix[i][j];
        }
    }
}

bool Matrix::scaleMatrix(int scalar) {
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            m_matrix[i][j] *= scalar;
        }
    }
}

bool Matrix::multiplyMatrix(const Matrix &rhs) {
    if (m_numCols != rhs.m_numRows) {
        return false;
    }
    int ** newMatrix = buildMatrix(m_numRows, rhs.m_numCols);

    for (int i = 0; i < m_numRows; i++) {
    for (int j = 0; j < rhs.m_numCols; j++) {
            for (int k = 0; k < m_numCols; k++) {
                newMatrix[i][j] += m_matrix[i][k] * rhs.m_matrix[k][j];
            }
        }
    }

    clear();
    m_numRows = m_numRows;
    m_numCols = rhs.m_numCols;
    m_matrix = newMatrix;
    newMatrix = nullptr;
}

void Matrix::transposeMatrix() {
    int ** newMatrix = buildMatrix(m_numCols, m_numRows);

    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numCols; j++) {
            newMatrix[j][i] = m_matrix[i][j];
        }
    }

    clear();
    m_numRows = m_numCols;
    m_numCols = m_numRows;
    m_matrix = newMatrix;
    newMatrix = nullptr;
}

int ** Matrix::buildMatrix(int numRows, int numCols) {
    int ** matrix = new int*[numRows];
    for (int i = 0; i < m_numRows; i++) {
        matrix[i] = new int[numCols]();
    }
    return matrix;
}
