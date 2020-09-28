#include "Square.h"

double Square::square() {
    return width * height;
}

double Square::perimeter() {
    return 2 * width + 2 * height;
}

double Square::mass() const {
    return mas;
}

CVector2D Square::position() {
    return CVector2D(lower_left_point.x + width / 2, lower_left_point.y + height / 2);
}

bool Square::operator==(const IPhysObject &ob) const {
    return this->mas == ob.mass();
}

bool Square::operator<(const IPhysObject &ob) const {
    return this->mas < ob.mass();
}

void Square::draw() {
    cout << this->classname() << endl
    << "coordinates of left lower point: (" << lower_left_point.x << ";" << lower_left_point.y << ")" << endl
    << "width: " << width << endl
    << "height: " << height << endl
    << "mas: " << mas << endl
    << "center of mas: (" << position().x << ";" << position().y << ")" << endl
    << "square: " << square() << endl
    << "perimeter: " << perimeter() << endl;
}

void Square::initFromDialog() {
    double x, y;
    cout << "Print coordinates of left lower point\nx:";
    cin >> x;
    cout << "y:";
    cin >> y;
    lower_left_point = CVector2D(x, y);
    cout << "width:";
    cin >> width;
    cout << "height:";
    cin >> height;
    cout << "mas:";
    cin >> mas;
}

const char *Square::classname() {
    return "Square";
}

unsigned int Square::size() {
    return sizeof(*this);
}