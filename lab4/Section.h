#ifndef LAB4_SECTION_H
#define LAB4_SECTION_H

#include "Interfaces.h"
#include <cmath>
#include <iostream>
using namespace std;

class Section: public IFigure {
private:
    double mas = 0;
    CVector2D point1, point2;
public:
    double  mass() const override;

    CVector2D position() override;

    bool operator==(const IPhysObject &ob) const override;

    bool operator<(const IPhysObject &ob) const override;

    void draw() override;

    void initFromDialog() override;

    const char *classname() override;

    unsigned int size() override;

    double square() override;

    double perimeter() override;
};

#endif //LAB4_SECTION_H
