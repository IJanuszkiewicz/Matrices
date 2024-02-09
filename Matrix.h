//
// Created by igo-j on 04/02/2024.
//

#ifndef MATRIX_H
#define MATRIX_H

namespace Matrices {

class Matrix {
    double **m_mat;
    int m_rows, m_cols;

public:
    Matrix(double **t_mat, int t_rows, int t_cols);
    Matrix(int t_rows, int t_cols);
    ~Matrix();

    Matrix &operator=(const Matrix& t_matrix);
    double &operator[](int t_row, int t_col);
    Matrix operator+(const Matrix& t_matrix);
    Matrix operator*(const Matrix& t_matrix);
    void print() const;
};

} // Matrices

#endif //MATRIX_H
