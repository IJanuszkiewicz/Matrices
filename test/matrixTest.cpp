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

TEST(MatrixTest, IndexingThrowsWithWrongArgument){
    Matrices::Matrix m(3,4);

    EXPECT_THROW(m(-1, 0), std::out_of_range);
    EXPECT_THROW(m(0, -1), std::out_of_range);
    EXPECT_THROW(m(-1, 0), std::out_of_range);
    EXPECT_THROW(m(3, 0), std::out_of_range);
    EXPECT_THROW(m(0, 4), std::out_of_range);
    EXPECT_THROW(m(5, 5), std::out_of_range);
    EXPECT_THROW(m(-1, -2), std::out_of_range);
}

TEST(MatrixTest, ChangingValuesWithIndexing){
    Matrices::Matrix m(2,2);
    m(1,0) = 0;
    EXPECT_DOUBLE_EQ(m(1,0), 0);
    m(1,0) = 1;
    EXPECT_DOUBLE_EQ(m(1,0), 1);
}

TEST(MatrixTest, WrongDimensionsThrowWhenMultiply){
    Matrices::Matrix m1(2,2), m2(3,3), m3(2,3);
    EXPECT_THROW(m1*m2, std::invalid_argument);
    EXPECT_THROW(m2*m3, std::invalid_argument);
}

TEST(MatrixTest, WrongDimensionsThrowWhenAdd){
    Matrices::Matrix m1(2,2), m2(3,3), m3(2,3);
    EXPECT_THROW(m1+m2, std::invalid_argument);
    EXPECT_THROW(m2+m3, std::invalid_argument);
    EXPECT_THROW(m1+m3, std::invalid_argument);
}

TEST(MatrixTest, OperatorEqualsChangesDimensions){
    Matrices::Matrix m1(2,2), m2(3,3);
    m1 = m2;
    EXPECT_EQ(m1.getCols(), m2.getCols());
    EXPECT_EQ(m2.getRows(), m1.getRows());
}