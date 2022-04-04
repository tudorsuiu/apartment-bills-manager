//
// Created by Tudor on 4/3/2022.
//

#include <iostream>
#include "Console.h"

void Console::showMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add entity." << '\n';
    std::cout << "2. Check entities." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::runMenu() {
    char option;
    Entity entity;
    do {
        showMenu();
        std::cin >> option;
        switch (option) {
            case '1': {
                std::cin >> entity;
                repository.addEntity(entity);
                break;
            }
            case '2': {
                Vector<Entity> v = repository.getAll();
                std::cout << v;
                break;
            }
            case 'x':
                break;
            default:
                std::cout << "Optiune gresita!" << '\n';
                break;
        }
    }while(option != 'x');
}