#include <iostream>
#include "procedures.h"

using namespace std;

int main() {
    int x1 = 5, y1 = 6;
    increase(&x1, y1);
    cout << x1 << endl;
    x1 = 5;
    increase(x1, y1);
    cout << x1 << endl << endl;

    double x2_1 = 12.34567;
    delete_whole_part(&x2_1);
    cout << x2_1 << endl;
    double x2_2 = 76.54321;
    delete_whole_part(x2_2);
    cout << x2_2 << endl << endl;

    ComplexNum com;
    com.x = 1;
    com.y = 2;
    change_to_conjugate(&com);
    cout << com.y << endl;
    change_to_conjugate(com);
    cout << com.y << endl << endl;

    Square sq;
    sq.p[0].x = 0;
    sq.p[0].y = 0;
    sq.p[1].x = 2;
    sq.p[1].y = 0;
    sq.p[2].x = 2;
    sq.p[2].y = 2;
    sq.p[3].x = 0;
    sq.p[3].y = 2;
    move_square(&sq, 3, 3);
    for (int i = 0; i < 4; ++i) {
        cout << "(" << sq.p[i].x << "; " << sq.p[i].y << ") ";
    }
    cout << endl;
    move_square(sq, -3, -3);
    for (int i = 0; i < 4; ++i) {
        cout << "(" << sq.p[i].x << "; " << sq.p[i].y << ") ";
    }
    return 0;
}