#ifndef LAB3_INTEGERS_H
#define LAB3_INTEGERS_H

#include <vector>
#include <iostream>

class Integers {
private:
    bool set[10]{};
public:
    Integers();
    Integers(std::vector<int > mas);
    Integers operator+(Integers set2);
    bool operator==(Integers set2);
    bool operator!=(Integers set2);
    Integers operator+=(int x);
    Integers operator-=(int x);
    void print();
};


#endif //LAB3_INTEGERS_H
