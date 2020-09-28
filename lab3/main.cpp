#include <iostream>
#include "Matrix.h"
#include "Integers.h"

using namespace std;

int main() {
    //operator* by number
    cout << "multiplication by number \n";
    Matrix matr = Matrix(1, 1, 1, 1, 1, 1, 1, 1, 1);
    matr = matr * 10;
    matr.print();
    cout << endl;

    matr = matr.operator*(2.5);
    matr.print();
    cout << endl << endl;


    Matrix matr1 = Matrix(9, 8, 7, 6, 5, 4, 3, 2, 1);
    Matrix matr2 = Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);

    //operator* by matrix
    cout << "multiplication by matrix \n";
    Matrix rez = matr1 * matr2;
    rez.print();
    cout << endl;

    rez = matr1.operator*(matr2);
    rez.print();
    cout << endl << endl;

    //operator+ and operator-
    cout << "matrix addition and subtraction \n";
    rez = matr1 + matr2;
    rez.print();
    cout << endl;

    rez = matr1.operator+(matr2);
    rez.print();
    cout << endl << endl;

    rez = matr1 - matr2;
    rez.print();
    cout << endl;

    rez = matr1.operator-(matr2);
    rez.print();
    cout << endl << endl;

    //operator<, operator>, operator== and operator!=
    cout << "Matrix comparison \n";
    Matrix matr3 = Matrix(9, 8, 7, 6, 5, 4, 3, 2, 1);
    bool rezult = matr1 == matr3;
    cout << rezult << endl;
    rezult = matr1 != matr3;
    cout << rezult << endl << endl;

    rezult = matr1.operator==(matr2);
    cout << rezult << endl;
    rezult = matr1.operator!=(matr2);
    cout << rezult << endl << endl;

    rezult = matr1 > matr2;
    cout << rezult << endl;
    rezult = matr1.operator<(matr2);
    cout << rezult << endl;
    cout << "\n\n\n";


    //  --INTEGERS--
    //operator+
    cout << "operator+" <<endl;
    vector<int> mas1 = {1, 3, 5, 2, 0};
    vector<int> mas2 = {1, 4, 9};
    Integers set1 = Integers(mas1);
    Integers set2 = Integers(mas2);
    Integers set_rez1 = set1 + set2;
    set_rez1.print();

    Integers set_rez2 = set1.operator+(set2);
    set_rez2.print();
    cout << endl;

    //operator+= and operator -=
    cout << "operator+= and operator -=" <<endl;
    vector<int> mas3 = {0, 9, 4, 5};
    Integers set3 = Integers(mas3);
    set3.print();
    set3 += 1;
    set3.print();
    set3 = set3.operator-=(4);
    set3.print();
    cout << endl;

    //operator== and operator!=
    cout << "operator== and operator!=" <<endl;
    vector<int> mas4 = {1, 2, 3, 4, 5};
    vector<int> mas6 = {1, 2, 3};
    Integers set4 = Integers(mas4);
    Integers set5 = Integers(mas4);
    Integers set6 = Integers(mas6);

    bool rez_bool = set4 == set5;
    cout << rez_bool << endl;
    rez_bool = set5.operator==(set6);
    cout << rez_bool << endl << endl;

    rez_bool = set4 != set5;
    cout << rez_bool << endl;
    rez_bool = set5.operator!=(set6);
    cout << rez_bool << endl << endl;
    return 0;
}