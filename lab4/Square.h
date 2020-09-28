#ifndef LAB4_SQUARE_H
#define LAB4_SQUARE_H

#include "Interfaces.h"
#include <iostream>
using namespace std;

class Square: public IFigure{
private:
    CVector2D lower_left_point;
    double width, height, mas;
public:
    double square() override;

    double perimeter() override;

    double mass() const override;

    CVector2D position() override;

    bool operator==(const IPhysObject &ob) const override;

    bool operator<(const IPhysObject &ob) const override;

    void draw() override;

    void initFromDialog() override;

    const char *classname() override;

    unsigned int size() override;
};


#endif //LAB4_SQUARE_H
