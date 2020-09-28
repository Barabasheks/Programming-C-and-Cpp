#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include <vector>
#include "Stack.h"
using namespace std;

class Menu {
public:
    static void startmenu();

private:
    static vector<Stack> stacks;
    static void create_new_stack();
    static void command_for_stack();
    static void delete_stack();
    static Stack create_by_size();
    static Stack create_by_list_stack();
    static Stack create_by_stack();
    static int choose_stack();
};

#endif //LAB2_MENU_H
