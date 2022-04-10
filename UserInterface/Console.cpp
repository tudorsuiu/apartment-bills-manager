//
// Created by Tudor on 4/3/2022.
//

#include <iostream>
#include "Console.h"

void Console::showMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add apartment bill." << '\n';
    std::cout << "2. Check apartments bills." << '\n';
    std::cout << "3. Update apartment bill." << '\n';
    std::cout << "4. Delete apartment bill." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::runMenu() {
    char option;
    do {
        showMenu();
        std::cin >> option;
        std::cout << '\n';
        switch (option) {
            case '1': {
                unsigned int apartmentNumber;
                std::cout << "Apartment number:"; std::cin >> apartmentNumber;
                char *billType = new char[15];
                std::cout << "Bill type:"; std::cin >> billType;
                unsigned int billTotal;
                std::cout << "Bill total:"; std::cin >> billTotal;

                apartmentService.create(apartmentNumber, billType, billTotal);
                break;
            }
            case '2': {
                std::cout << apartmentService.read();
                break;
            }
            case '3': {
                int position;
                std::cout << "Id:"; std::cin >> position;

                unsigned int apartmentNumber;
                std::cout << "New apartment number:"; std::cin >> apartmentNumber;
                char *billType = new char[15];
                std::cout << "New bill type:"; std::cin >> billType;
                unsigned int billTotal;
                std::cout << "New bill total:"; std::cin >> billTotal;

                apartmentService.update(position - 1, apartmentNumber, billType, billTotal);
                break;
            }
            case '4': {
                int position;
                std::cout << "Delete id:"; std::cin >> position;

                apartmentService.del(position - 1);
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