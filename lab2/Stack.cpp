#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    max_kol = 0;
    kol = 0;
}

Stack::Stack(int size) {
    list = new int[size];
    max_kol = size;
    kol = 0;
}

Stack::Stack(stack<int> stack) {
    max_kol = stack.size();
    kol = max_kol;
    list = new int[max_kol];
    for (int i = kol - 1; i >= 0; --i) {
        list[i] = stack.top();
        stack.pop();
    }
}

Stack::Stack(Stack const &stack) {
    this->max_kol = stack.max_kol;
    this->kol = stack.kol;
    this->list = new int[kol];
    for (int i = 0; i < kol; ++i) {
        this->list[i] = stack.list[i];
    }
}

void Stack::push(int x) {
    if(kol < max_kol){
        list[kol] = x;
        kol++;
    }
}

void Stack::pop() {
    kol--;
}

int Stack::kol_of_elements() {
    return kol;
}

bool Stack::is_empty() {
    return kol == 0;
}

int Stack::front_el() {
    if (kol > 0)
        return list[kol - 1];
    else
        return 0;
}

void Stack::print() {
    cout << "[ ";
    for (int i = 0; i < kol; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
}