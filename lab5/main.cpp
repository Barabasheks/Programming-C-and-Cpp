#include <iostream>
#include "Array_T.h"
using namespace std;

template <typename T>
T min_digit(T x, T y){
    if (x < y)
        return x;
    else
        return y;
}

int main() {
    //T func
    int a = 5;
    int c = 7;
    double b = 10.2;
    double d = 10.3;
    cout << min_digit(a, c) << " " << min_digit(b, d);

    //T class
    int n;
    cin >> n;
    Array_T<int> mas (n);
    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
    }
    cout << endl;

    cin >> n;
    Array_T<double> mas_double (n);
    for (int i = 0; i < n; ++i) {
        cin >> mas_double[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << mas_double[i] << " ";
    }
    cout << endl;
    try {
        mas[-1] = 6;
    }
    catch (Array_exc& exception){
        exception.print_er();
    }

    try {
        mas_double[n] = 6;
    }
    catch (Array_exc& exception){
        exception.print_er();
    }
    return 0;
}
