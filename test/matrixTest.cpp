#include <gtest/gtest.h>
#include "../include/Matrix.h"

TEST(MatrixTest, Multiply){
    Matrices::Matrix mat(3,3);
    mat(0,0) = 1; mat(0,1) = 2; mat(0,2) = 3;
    mat(1,0) = 4; mat(1,1) = 5; mat(1,2) = 6;
    mat(2,0) = 7; mat(2,1) = 8; mat(2,2) = 9; 

    
    Matrices::Matrix exactSquare(3,3);
    exactSquare(0,0) = 30; exactSquare(0,1) = 36; exactSquare(0,2) = 42;
    exactSquare(1,0) = 66; exactSquare(1,1) = 81; exactSquare(1,2) = 96;
    exactSquare(2,0) = 102; exactSquare(2,1) = 126; exactSquare(2,2) = 150;

    Matrices::Matrix testSquare = mat*mat;

    for(int row = 0; row < 3; ++row){
        for (int col = 0; col < 3; ++col){
            EXPECT_DOUBLE_EQ(testSquare(row, col), exactSquare(row, col));
        }
    }
}