#include <iostream>
#include <algorithm>
#include "Circular_buffer.h"
using namespace std;

int main() {
    Circular_buffer<int> buf(4);

    //put_in_end
    cout << "put_in_end" << endl;
    buf.put_in_end(1);
    buf.put_in_end(3);
    buf.put_in_end(2);
    buf.put_in_end(6);
    buf.put_in_end(4);
    buf.put_in_end(5);
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //sort
    cout << "sort():" << endl;
    sort(buf.begin(), buf.end());
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //put_in_begin
    cout << "put_in_begin" << endl;
    buf.put_in_begin(7);
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //find
    cout << "find" << endl;
    auto item = find(buf.begin(), buf.end(), 5);
    if (item != buf.end())
        cout << *item << endl << endl;
    else
        cout << "NO" << endl << endl;

    //put_in
    cout << "put_in" << endl;
    buf.put_in(item, 8);
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //delete_in
    cout << "delete_in" << endl;
    item = find(buf.begin(), buf.end(), 5);
    buf.delete_in(item);
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //put_in
    cout << "put_in" << endl;
    item = find(buf.begin(), buf.end(), 8);
    buf.put_in(item, 9);
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //delete_end
    cout << "delete_end" << endl;
    buf.delete_end();
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //delete_begin
    cout << "delete_begin" << endl;
    buf.delete_begin();
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //change_capacity
    cout << "change capacity" << endl;
    buf.change_capacity(6);
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;
    //put_in_end
    cout << "put_in_end" << endl;
    buf.put_in_end(10);
    buf.put_in_end(11);
    buf.put_in_end(12);
    buf.put_in_end(13);
    buf.put_in_end(14);
    buf.put_in_end(12);
    for (Circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //cout with []
    cout << "cout with []" << endl;
    for (int i = 0; i < 6; ++i) {
        cout << buf[i] << " ";
    }
    cout << endl << endl;

    //algorithm
    cout << "count():" << endl;
    cout << count(buf.begin(), buf.end(), 12) << endl << endl;

    cout << "repalce() 12 to 20:" << endl;
    replace(buf.begin(), buf.end(), 12, 20);
    for (int i = 0; i < 6; ++i) {
        cout << buf[i] << " ";
    }
    return 0;
}