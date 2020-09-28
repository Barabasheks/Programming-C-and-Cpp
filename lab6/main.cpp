#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>

using namespace std;

class Point{
public:
    int x, y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

};

template <typename Iterator, typename Comp>
bool any_of(Iterator begin, Iterator end, Comp comp){
    while (begin != end){
        if (comp(*begin))
            return true;
        begin++;
    }
    return false;
}

template <typename Iterator, typename Type>
Iterator find_backward(Iterator begin, Iterator end, Type element){
    Iterator cur = end - 1;
    while(cur != begin){
        if (*cur == element)
            return cur;
        cur--;
    }
    return end;
}

template <typename Iterator, typename Comp>
bool is_partitioned(Iterator begin, Iterator end, Comp comp){
    while(comp(*begin) && (begin != end))
        begin++;
    while (begin != end) {
        if (comp(*begin))
            return false;
        begin++;
    }
    return true;
}

template <typename Type>
class Comp_for_any_of {
public:
    bool operator()(Type it) const {
        return it == 2;
    }
};

class Comp_for_any_of_point {
public:
    bool operator()(Point it) const {
        return it.x == it.y;
    }
};

class Comp_for_is_partitioned_array{
public:
    bool operator()(int el) const {
        return el < 4;
    }
};

class Comp_for_is_partitioned_set{
public:
    bool operator()(int el) const {
        return el == 3;
    }
};

int main() {
    vector<int> vec = {5, 4, 2, 1};
    set<float> any_set = {5.1, 4.1, 2.1, 1.1};
    vector<Point> vec_point = {Point(1, 2), Point(2,2), Point(3,2)};
    //any_of
    cout << "any_of:" << endl;
    cout << any_of(vec.begin(), vec.end(), Comp_for_any_of<int>()) << endl;  //find el, that el = 2
    cout << any_of(any_set.begin(), any_set.end(), Comp_for_any_of<float>()) << endl; //find el, that el = 2
    cout << any_of(vec_point.begin(), vec_point.end(), Comp_for_any_of_point()) << endl; //find point, which have x = y

    //find_backward
    deque<string> deq = {"5", "4", "2", "1"};
    cout << "find_backward:" << endl;
    string str1 = "2";
    auto ptr1 = find_backward(deq.begin(), deq.end(), str1); // find "2"
    if (ptr1 != deq.end())
        cout << *ptr1 << endl;
    else
        cout << "not found" << endl;

    auto ptr2 = find_backward(vec.begin(), vec.end(), -1); // find -1
    if (ptr2 != vec.end())
        cout << *ptr2 << endl;
    else
        cout << "not found" << endl;

    //is_partitioned
    cout << "is_partitioned:" << endl;
    vector<int> pars_array = {1, 2, 3, 1, 2, 7, 5, 4, 9};
    vector<int> not_pars_array = {2, 3, 4, 5, 9, 1, 2};
    set<int> pars_set = {1, 2, 3, 1, 2, 7, 5, 4, 9};
    set<int> not_pars_set = {2, 3, 4, 3, 9, 1, 3};
    cout << is_partitioned(pars_array.begin(), pars_array.end(), Comp_for_is_partitioned_array()) << endl;
    cout << is_partitioned(not_pars_array.begin(), not_pars_array.end(), Comp_for_is_partitioned_array()) << endl;
    cout << is_partitioned(pars_set.begin(), pars_set.end(), Comp_for_is_partitioned_array()) << endl;
    cout << is_partitioned(not_pars_set.begin(), not_pars_set.end(), Comp_for_is_partitioned_set());
    return 0;
}
