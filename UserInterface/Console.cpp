//
// Created by Tudor on 4/3/2022.
//

#include <iostream>
#include "Console.h"

void Console::showMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add apartment bills." << '\n';
    std::cout << "2. Check bills." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::runMenu() {
    char option;
    Apartment apartment;
    do {
        showMenu();
        std::cin >> option;
        switch (option) {
            case '1': {
                std::cin >> apartment;
                repository.addEntity(apartment);
                break;
            }
            case '2': {
                std::cout << repository;
                break;
            }
            case 'x':
                break;
            default:
                std::cout << "Optiune gresita! Reincercati!";
                break;
        }
    }while(option != 'x');
}