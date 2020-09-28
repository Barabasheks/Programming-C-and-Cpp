#ifndef LAB1_PROCEDURES_H
#define LAB1_PROCEDURES_H

void increase(int* x, int y);
void increase(int& x, int y);

void delete_whole_part(double * x);
void delete_whole_part(double & x);

struct ComplexNum{
    int x;
    int y;
};
void change_to_conjugate(ComplexNum* com);
void change_to_conjugate(ComplexNum& com);

struct Point{
    int x;
    int y;
};
struct Square{
    Point p[4];
};
void move_square(Square* sq, int x, int y);
void move_square(Square& sq, int x, int y);
#endif //LAB1_PROCEDURES_H
