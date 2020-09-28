#include "Menu.h"
#include <iostream>
using namespace std;

vector<Stack> Menu::stacks;

void Menu::startmenu() {
    cout << "Stacks: " << endl;
    for (int i = 0; i < stacks.size(); ++i) {
        cout << i + 1 << ": ";
        stacks[i].print();
    }
    cout << endl << "Menu:" << endl;
    cout << "1: Create new stack" << endl;
    cout << "2: Use command for stack" << endl;
    cout << "3: Delete stack" << endl;
    cout << "Command: ";
    int command;
    cin >> command;
    switch (command){
        case 1:
            create_new_stack();
            break;
        case 2:
            command_for_stack();
            break;
        case 3:
            delete_stack();
            break;
        default:
            //system("CLS");
            cout << "Wrong command!" << endl << endl;
            startmenu();
    }
}

void Menu::create_new_stack() {
    cout << "Create by: \n"
            "1: size \n"
            "2: list stack \n"
            "3: stack \n"
            "Command:";
    int command;
    cin >> command;
    Stack stack;
    switch (command){
        case 1:
            stack = create_by_size();
            break;
        case 2:
            stack = create_by_list_stack();
            break;
        case 3:
            stack = create_by_stack();
            break;
        default:
            cout << "Wrong command!" << endl << endl;
            startmenu();
    }
    stacks.push_back(stack);
    startmenu();
}

void Menu::command_for_stack() {
    int id_stack = choose_stack();
    cout << "Choose command: \n"
            "1: push number \n"
            "2: pop number \n"
            "3: print front number \n"
            "4: print size \n"
            "5: check on empty \n"
            "Command: ";
    int command, num;
    cin >> command;
    switch (command){
        case 1:
            cout << "Num: ";
            cin >> num;
            stacks[id_stack].push(num);
            break;
        case 2:
            stacks[id_stack].pop();
            break;
        case 3:
            cout << "Front num: " << stacks[id_stack].front_el() << endl;
            break;
        case 4:
            cout << "Size: " << stacks[id_stack].kol_of_elements() << endl;
            break;
        case 5:
            cout << "Empty: " << stacks[id_stack].is_empty()<< endl;
            break;
        default:
            cout << "Wrong command!";
            command_for_stack();
            break;
    }
    startmenu();
}

void Menu::delete_stack() {
    int id_stack = choose_stack();
    vector<Stack> new_stacks;
    for (int i = 0; i < stacks.size(); ++i) {
        if (i != id_stack)
            new_stacks.push_back(stacks[i]);
    }
    stacks = new_stacks;
    startmenu();
}

Stack Menu::create_by_size() {
    cout << "Size: ";
    int size;
    cin >> size;
    return Stack(size);
}

Stack Menu::create_by_list_stack() {
    cout << "Use ] to end stack!" << endl;
    cout << "list stack: [ ";
    string el;
    stack<int> list_stack;
    cin >> el;
    while(el != "]") {
        list_stack.push(stoi(el));
        cin >> el;
    }
    return Stack(list_stack);
}

Stack Menu::create_by_stack() {
    int id_stack = choose_stack();
    return Stack(stacks[id_stack]);
}

int Menu::choose_stack() {
    cout << "Choose stack:" << endl;
    for (int i = 0; i < stacks.size(); ++i) {
        cout << i << ": " << "[ ";
        stacks[i].print();
    }
    cout << endl << "Stack_id: ";
    int id_stack = stacks.size();
    while (id_stack >= stacks.size() || id_stack < 0){
        cin >> id_stack;
        if (id_stack >= stacks.size() || id_stack < 0){
            cout << "Id is out of stacks!" << endl;
            cout << "Stack_id: ";
        }
    }
    return id_stack;
}
