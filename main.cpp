#include <iostream>
#include "Matrix.h"

#define ROWS 1000
#define COLS 1000

int main() {
    double num = 1;
    double **mat = new double*[ROWS];
    for(int row = 0; row < ROWS; ++row) {
        mat[row] = new double[COLS];
        for(int col = 0; col < COLS; ++col) {
            mat[row][col] = num++;
        }
    }

    Matrices::Matrix matrix(mat, ROWS, COLS);
    //matrix.print();
    //std::cout << std::endl;
    matrix*matrix;

}
