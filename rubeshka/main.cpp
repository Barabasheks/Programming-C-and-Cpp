#include <iostream>
using namespace std;

class Polinom{
private:
    int step;
    int* koefs;
public:
    Polinom(int step, int* list_of_koefs){
        this->step = step;
        this->koefs = list_of_koefs;
    }
    Polinom operator+ (Polinom& pol2){
        int step3 = max(this->step, pol2.step);
        int* koefs = new int[step3 + 1];
        for (int i = 0; i < step3 + 1; ++i) {
            if (i <= this->step && i <= pol2.step){
                koefs[i] = this->koefs[i] + pol2.koefs[i];
            }
            if (i <= this->step && i > pol2.step){
                koefs[i] = this->koefs[i];
            }
            if (i > this->step && i <= pol2.step){
                koefs[i] = pol2.koefs[i];
            }
        }
        return Polinom(step3, koefs);
    }

    Polinom operator- (Polinom& pol2){
        int step3 = max(this->step, pol2.step);
        int* koefs = new int[step3 + 1];
        for (int i = 0; i < step3 + 1; ++i) {
            if (i <= this->step && i <= pol2.step){
                koefs[i] = this->koefs[i] - pol2.koefs[i];
            }
            if (i <= this->step && i > pol2.step){
                koefs[i] = this->koefs[i];
            }
            if (i > this->step && i <= pol2.step){
                koefs[i] = -pol2.koefs[i];
            }
        }
        return Polinom(step3, koefs);
    }
};

int main() {
    int* list = new int[3];
    list[0] = 0;
    list[1] = 1;
    list[2] = 2;
    Polinom p = Polinom(3, list);
    Polinom p = Polinom(3, list);
    return 0;
}
