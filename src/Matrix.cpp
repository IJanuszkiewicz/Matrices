//
// Created by igo-j on 04/02/2024.
//

#include "../include/Matrix.h"

#include <iomanip>
#include <iostream>
#include <stdexcept>

#define PRINT_PRECISION 4

namespace Matrices {
    Matrix::Matrix(double** t_mat, int t_rows, int t_cols): m_rows(t_rows), m_cols(t_cols) {
        m_mat = new double*[m_rows];
        for(int row = 0; row < m_rows; ++row) {
            m_mat[row] = new double[m_cols];
            for(int col = 0; col < m_cols; ++col) {
                m_mat[row][col] = t_mat[row][col];
            }
        }
    }

    Matrix::Matrix(int t_rows, int t_cols):m_rows(t_rows), m_cols(t_cols) {
        m_mat = new double*[m_rows];
        for(int row = 0; row < m_rows; ++row) {
            m_mat[row] = new double[m_cols];
        }
    }

    Matrix::~Matrix() {
        for(int row = 0; row < m_rows; ++row) {
            delete[] m_mat[row];
        }
        delete[] m_mat;
    }

    Matrix& Matrix::operator=(const Matrix& t_matrix) {
        if(m_cols == t_matrix.m_cols && m_rows == t_matrix.m_rows) {
            for(int row = 0; row < m_rows; ++row) {
                for(int col = 0; col < m_cols; ++col) {
                    m_mat[row][col] = t_matrix.m_mat[row][col];
                }
            }
        } else if(m_rows == t_matrix.m_rows) {
            for(int row = 0; row < m_rows; ++row) {
                delete[] m_mat[row];
                m_mat[row] = new double[t_matrix.m_cols];
                m_cols = t_matrix.m_cols;
                for(int col = 0; col < t_matrix.m_cols; ++col) {
                    m_mat[row][col] = t_matrix.m_mat[row][col];
                }
            }
        } else if(m_cols == t_matrix.m_cols) {
            double **oldMat = m_mat;
            m_mat = new double*[t_matrix.m_rows];
            if(m_rows > t_matrix.m_rows) {
                for(int row = 0; row < t_matrix.m_rows; ++row) {
                    m_mat[row] = oldMat[row];
                    for(int col = 0; col < m_cols; ++col) {
                        m_mat[row][col] = t_matrix.m_mat[row][col];
                    }
                }
                for(int row = t_matrix.m_rows; row < m_rows; ++row) {
                    delete[] oldMat[row];
                }
            } else {
                for(int row = 0; row < m_rows; ++row) {
                    m_mat[row] = oldMat[row];
                    for(int col = 0; col < m_cols; ++col) {
                        m_mat[row][col] = t_matrix.m_mat[row][col];
                    }
                }
                for (int row = m_rows; row < t_matrix.m_rows; ++row){
                    m_mat[row] = new double[m_cols];
                    for(int col = 0; col < m_cols; ++col){
                        m_mat[row][col] = t_matrix.m_mat[row][col];
                    }
                }
            }
            delete[] oldMat;
            m_rows = t_matrix.m_rows;
        } else {
            for(int row = 0; row < m_rows; ++row){
                delete[] m_mat[row];
            }
            delete[] m_mat;

            m_mat = new double*[t_matrix.m_rows];
            for(int row = 0; row < t_matrix.m_rows; ++row){
                m_mat[row] = new double[t_matrix.m_cols];
                for (int col = 0; col < t_matrix.m_cols; ++col){
                    m_mat[row][col] = t_matrix.m_mat[row][col];
                }
            }
            m_cols = t_matrix.m_cols;
            m_rows = t_matrix.m_rows;
        }
        return *this;
    }

    double& Matrix::operator()(int t_row, int t_col) {
        if(t_row < 0 || t_col < 0 || t_row >= m_rows || t_col >= m_cols) {
            throw std::out_of_range("matrix index out of range");
        }
        return m_mat[t_row][t_col];
    }

    Matrix Matrix::operator+(const Matrix& t_matrix) {
        if(m_cols != t_matrix.m_cols || m_rows != t_matrix.m_rows) {
            throw std::invalid_argument("addition: matrices dimensions don't match");
        }
        Matrix sum(m_rows, m_cols);
        for(int row = 0; row < m_rows; ++row ) {
            for(int col = 0; col < m_cols; ++col) {
                sum.m_mat[row][col] = m_mat[row][col] + t_matrix.m_mat[row][col];
            }
        }
        return sum;
    }

    Matrix Matrix::operator*(const Matrix& t_matrix) {
        if (m_cols != t_matrix.m_rows) {
            throw std::invalid_argument("multiplication: dimensions aren't correct");
        }
        Matrix toRet(m_rows, t_matrix.m_cols);
        double prod;
        for(int row = 0; row < m_rows; ++row) {
            for(int col = 0; col < t_matrix.m_cols; ++col) {
                prod = 0;
                for (int el = 0; el < m_cols; ++el) {
                    prod += m_mat[row][el]*t_matrix.m_mat[el][col];
                }
                toRet.m_mat[row][col] = prod;
            }
        }
        return toRet;
    }

    void Matrix::print() const {
        std::cout << std::scientific << std::setprecision(PRINT_PRECISION);
        for(int row = 0; row < m_rows; ++row ) {
            for(int col = 0; col < m_cols; ++col) {
                std::cout << m_mat[row][col] << ' ';
            }
            std::cout << std::endl;
        }
    }
} // Matrices