#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    container<int> buf;
    buf.push_end(1);
    buf.push_end(3);
    buf.push_end(2);
    sort(buf.begin(), buf.end());
    return 0;
}
