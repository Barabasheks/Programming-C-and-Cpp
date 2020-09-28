#include <string>
#include "procedures.h"

using namespace std;

void increase(int* x, int y){
    *x = *x + y;
}
void increase(int& x, int y){
    x = x + y;
}

void delete_whole_part(double* x){
    int whole_part = *x;
    double fractional_part = *x - whole_part;
    string frac = to_string(fractional_part);
    string new_fraq;
    for (int i = 2; i < frac.length(); ++i) {
        new_fraq += frac[i];
    }
    int num = stoi(new_fraq);
    while(num % 10 == 0){
        num = num / 10;
    }
    *x = num;
}
void delete_whole_part(double& x){
    int whole_part = x;
    double fractional_part = x - whole_part;
    string frac = to_string(fractional_part);
    string new_fraq;
    for (int i = 2; i < frac.length(); ++i) {
        new_fraq += frac[i];
    }
    int num = stoi(new_fraq);
    while(num % 10 == 0){
        num = num / 10;
    }
    x = num;
}

void change_to_conjugate(ComplexNum* com){
    (*com).y *= -1;
};
void change_to_conjugate(ComplexNum& com){
    com.y *= -1;
}

void move_square(Square* sq, int x, int y){
    for (int i = 0; i < 4; ++i) {
        sq->p[i].x += x;
        sq->p[i].y += y;
    }
}
void move_square(Square& sq, int x, int y){
    for (int i = 0; i < 4; ++i) {
        sq.p[i].x += x;
        sq.p[i].y += y;
    }
}
