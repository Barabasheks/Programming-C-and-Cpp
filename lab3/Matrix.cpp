#include "Matrix.h"

using namespace std;

Matrix Matrix::operator*(Matrix matr2) {
    Matrix rez = Matrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                rez.matr[i][j] += this->matr[i][k] * matr2.matr[k][j];
            }
        }
    }
    return rez;
}

Matrix Matrix::operator*(double x) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            this->matr[i][j] = this->matr[i][j] * x;
        }
    }
    return *this;
}

bool Matrix::operator<(Matrix matr2) {
    return this->sum_el() < matr2.sum_el();
}

bool Matrix::operator>(Matrix matr2) {
    return this->sum_el() > matr2.sum_el();
}

bool Matrix::operator!=(Matrix matr2) {
    return !(*this == matr2);
}

bool Matrix::operator==(Matrix matr2) {
    bool equal = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            equal = equal && (this->matr[i][j] == matr2.matr[i][j]);
        }
    }
    return equal;
}

Matrix Matrix::operator+(Matrix matr2) {
    Matrix rez = Matrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            rez.matr[i][j] = this->matr[i][j] + matr2.matr[i][j];
        }
    }
    return rez;
}

Matrix Matrix::operator-(Matrix matr2) {
    Matrix rez = Matrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            rez.matr[i][j] = this->matr[i][j] - matr2.matr[i][j];
        }
    }
    return rez;
}

void Matrix::insert(int i, int j, int x) {
    this->matr[i][j] = x;
}

void Matrix::print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << this->matr[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix::Matrix(int x11, int x12, int x13, int x21, int x22, int x23, int x31, int x32, int x33) {
    matr[0][0] = x11;
    matr[0][1] = x12;
    matr[0][2] = x13;
    matr[1][0] = x21;
    matr[1][1] = x22;
    matr[1][2] = x23;
    matr[2][0] = x31;
    matr[2][1] = x32;
    matr[2][2] = x33;
}

int Matrix::sum_el() {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum += matr[i][j];
        }
    }
    return sum;
}
