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

Matrix::~Matrix() {
    clear();
}

void Matrix::clear() {
    for (int i = 0; i < m_numCols; i++) {
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

bool Matrix::addMatrix(const Matrix &rhs)
{
    if (m_numCols != rhs.m_numCols && m_numRows != rhs.m_numRows) {
        return false;
    }

    for (int i = 0; i < m_numRows; i++) {
        for(int j = 0; j < m_numCols; j++) {
            m_matrix[i][j] += rhs.m_matrix[i][j];
        }
    }
}

bool Matrix::scaleMatrix(int scalar) {
    for (int i = 0; i < m_numRows; i++) {
        for(int j = 0; j < m_numCols; j++) {
            m_matrix[i][j] *= scalar;
        }
    }
}

bool Matrix::multiplyMatrix(const Matrix &rhs) {
    if (m_numCols != rhs.m_numRows) {
        return false;
    }
    int ** newMatrix = buildMatrix(m_numRows, rhs.m_numCols);

    for(int i = 0; i < rhs.m_numCols; i++) {
        for(int j = 0; j < m_numRows; j++) {
            
        }
    }

}

int ** Matrix::buildMatrix(int numRows, int numCols) {
    int ** matrix = new int*[numCols];
    for (int i = 0; i < m_numCols; i++) {
        matrix[i] = new int[numRows];
    }
    return matrix;
}