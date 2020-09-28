#ifndef LAB3_MATRIX_H
#define LAB3_MATRIX_H

#include <iostream>

class Matrix {
private:
    double matr[3][3]{};

public:
    Matrix(int x11, int x12, int x13,
           int x21, int x22, int x23,
           int x31, int x32, int x33);
    Matrix operator*(Matrix matr2);
    Matrix operator*(double x);
    Matrix operator-(Matrix matr2);
    Matrix operator+(Matrix matr2);
    bool operator==(Matrix matr2);
    bool operator!=(Matrix matr2);
    bool operator>(Matrix matr2);
    bool operator<(Matrix matr2);
    void insert(int i, int j, int x);
    void print();
    int sum_el();
};


#endif //LAB3_MATRIX_H
