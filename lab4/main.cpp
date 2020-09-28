#include "Section.h"
#include "Square.h"
#include <vector>

using namespace std;

enum Menu{
    ADD_SECTION = 1,
    ADD_SQUARE,
    PRINT_ALL_FIGURES,
    SUM_SQUARE,
    SUM_PERIMETER,
    SUM_CENTER_MAS,
    SUM_SIZE,
    SORT_BY_MAS,
    EXIT,
};

int main() {
    vector<IFigure*> figures;
    int point = 0;
    Menu point_of_menu;
    bool wrong_command = false;
    do{
        if (wrong_command)
            cout << "Wrong command!\n\n";
        wrong_command = false;
        cout << "1) Add section\n"
                "2) Add square\n"
                "3) Print all figures\n"
                "4) Total square\n"
                "5) Total perimeter\n"
                "6) Total center of mas\n"
                "7) Total size\n"
                "8) Sort figures by mas\n"
                "9) Exit\n"
                "Command:";
        cin >> point;
        cout << "\n";
        point_of_menu = static_cast<Menu>(point);
        switch (point_of_menu){
            case ADD_SECTION: {
                Section* section = new Section();
                section->initFromDialog();
                figures.push_back(section);
                break;
            }
            case ADD_SQUARE: {
                Square* square = new Square();
                square->initFromDialog();
                figures.push_back(square);
                break;
            }
            case PRINT_ALL_FIGURES: {
                cout << "Figures: \n";
                for (int i = 0; i < figures.size(); ++i) {
                    cout << i + 1 << ".\n";
                    figures[i]->draw();
                    cout << endl;
                }
                break;
            }
            case SUM_SQUARE: {
                double sum_square = 0;
                for (int i = 0; i < figures.size(); ++i) {
                    sum_square += figures[i]->square();
                }
                cout << "Sum of square: " << sum_square << endl;
                break;
            }
            case SUM_PERIMETER: {
                double sum_perimeter = 0;
                for (int i = 0; i < figures.size(); ++i) {
                    sum_perimeter += figures[i]->perimeter();
                }
                cout << "Sum of perimeter: " << sum_perimeter << endl;
                break;
            }
            case SUM_CENTER_MAS: {
                double sum_x = 0, sum_y = 0, sum_mas = 0;
                for (int i = 0; i < figures.size(); ++i) {
                    sum_x += figures[i]->position().x * figures[i]->mass();
                    sum_y += figures[i]->position().y * figures[i]->mass();
                    sum_mas += figures[i]->mass();
                }
                cout << "Sum center mas: (" <<sum_x/sum_mas << ";" << sum_y/sum_mas << ")\n";
                break;
            }
            case SUM_SIZE: {
                unsigned int sum_size = 0;
                for (int i = 0; i < figures.size(); ++i) {
                    sum_size += figures[i]->size();
                }
                cout << "Sum size: " << sum_size << endl;
                break;
            }
            case SORT_BY_MAS: {
                for (int i = 0; i < figures.size(); i++) {
                    for (int j = 0; j < figures.size() - 1; j++) {
                        if (!(*figures[j] < *figures[j + 1])) {
                            swap(figures[j], figures[j + 1]);
                        }
                    }
                }
                break;
            }
            default:
                wrong_command = true;
        }
    } while (point_of_menu != EXIT);
    return 0;
}
