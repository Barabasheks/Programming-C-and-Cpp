#include "Integers.h"

using namespace std;

Integers::Integers(vector<int> mas) {
    for (int i: mas) {
        this->set[i] = true;
    }
}

Integers Integers::operator+(Integers set2) {
    Integers integ = Integers();
    for (int i = 0; i < 10; ++i) {
        integ.set[i] = this->set[i] || set2.set[i];
    }
    return integ;
}

bool Integers::operator==(Integers set2) {
    bool equal = true;
    for (int i = 0; i < 10; ++i) {
        equal = equal && this->set[i] == set2.set[i];
    }
    return equal;
}

bool Integers::operator!=(Integers set2) {
    return !(*this == set2);
}

Integers Integers::operator+=(int x) {
    set[x] = 1;
    return *this;
}

Integers Integers::operator-=(int x) {
    set[x] = 0;
    return *this;
}

void Integers::print() {
    for (int i = 0; i < 10; ++i) {
        if(this->set[i] == 1)
            cout << i << " ";
    }
    cout << endl;
}

Integers::Integers() {
    for (int i = 0; i < 10; ++i) {
        set[i] = false;
    }
}
