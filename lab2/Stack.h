#ifndef LAB2_STACK_H
#define LAB2_STACK_H

#include <stack>
#include <string>
using namespace std;

class Stack {
private:
    int *list;
    int kol;
    int max_kol;
public:
    Stack();
    Stack(Stack const &stack);
    Stack(int size);
    Stack(stack<int> stack);
    void push(int x);
    void pop();
    int kol_of_elements();
    bool is_empty();
    int front_el();
    void print();
};


#endif //LAB2_STACK_H
