#include "Section.h"

double Section::mass() const {
    return mas;
}

CVector2D Section::position() {
    CVector2D center = CVector2D((point1.x + point2.x) / 2, (point1.y + point2.y) / 2);
    return center;
}

bool Section::operator==(const IPhysObject &ob) const {
    return ob.mass() == this->mas;
}

bool Section::operator<(const IPhysObject &ob) const {
    return this->mas < ob.mass();
}

void Section::draw() {
    cout << this->classname() << ":\n"
         << "mass: " << mas << endl
         << "center of mas: (" << position().x << ";" << position().y << ")" << endl
         << "point1: (" << point1.x << "; " << point1.y << ")" << endl
         << "point2: (" << point2.x << "; " << point2.y << ")" << endl
         << "square: " << this->square() << endl
         << "perimeter: " << this->perimeter() << endl;
}

void Section::initFromDialog() {
    cout << "mas:";
    cin >> mas;
    double x1, x2, y1, y2;
    cout << "x1:";
    cin >> x1;
    cout << "y1:";
    cin >> y1;
    cout << "x2:";
    cin >> x2;
    cout << "y2:";
    cin >> y2;
    point1 = CVector2D(x1, y1);
    point2 = CVector2D(x2, y2);
}

const char *Section::classname() {
    return "Section";
}

unsigned int Section::size() {
    return sizeof(*this);
}

double Section::square() {
    return 0;
}

double Section::perimeter() {
    return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}
