#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> arr2 {-3.28, -8.21, 5.07, 0.63, 5.04, -3.41, 3.64, -0.62, 5.54, 4.77};
    for (int i = 0; i < (int)arr2.size() - 1; ++i)
        for (int j = 0; j < (int)arr2.size() - 1 - i; ++j)
            if (arr2[j] > arr2[j + 1])
                std::swap(arr2[j], arr2[j + 1]);
    for (int k = 0; k < arr2.size(); ++k) {
        cout << arr2[k] << " ";
    }
    return 0;
}
