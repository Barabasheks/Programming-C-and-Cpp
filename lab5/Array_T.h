#ifndef LAB5_ARRAY_T_H
#define LAB5_ARRAY_T_H
#include <string>

class Array_exc{
private:
    std::string error_massage;
public:
    Array_exc(std::string error_massage){
        this->error_massage = error_massage;
    }
    void print_er(){
        std::cout << error_massage << std::endl;
    }
};

template <typename T>
class Array_T {
private:
    int length = 0;
    T* array = nullptr;

public:
    Array_T(int n){
        length = n;
        array = new T[length];
    }
    T& operator[](int index){
        if (index < 0 || index >= length)
            throw Array_exc("index out of range");
        return array[index];
    }
};


#endif //LAB5_ARRAY_T_H
