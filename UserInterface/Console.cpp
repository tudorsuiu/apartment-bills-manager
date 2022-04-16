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
    std::cout << "5. Deletes all apartment bills for an apartment." << '\n';
    std::cout << "6. Deletes all apartment bills from an interval of apartments." << '\n';
    std::cout << "7. Deletes all apartment bills that contain a specified type." << '\n';
    std::cout << "8. Update by apartment number and type." << '\n';
    std::cout << "9. Show all bills for an apartment." << '\n';
    std::cout << "0. Show all bills above a specified price." << '\n';
    std::cout << "a. Show all bills equal to a specified price." << '\n';
    std::cout << "b. Determine the sum of all bills of a specified type." << '\n';
    std::cout << "c. Determine the highest bill of an apartment." << '\n';
    std::cout << "d. Sort the bills of a specified type descending by total." << '\n';
    std::cout << "e. Filter by type." << '\n';
    std::cout << "f. Filter by total (under a specified price)." << '\n';
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

                std::string billType;
                std::cout << "Bill type:"; std::cin >> billType;
                const char *billType_char = billType.c_str();

                unsigned int billTotal;
                std::cout << "Bill total:"; std::cin >> billTotal;
                Apartment apartment(apartmentNumber, billType_char, billTotal);

                apartmentService.create(apartment);
                break;
            }
            case '2': {
                std::cout << apartmentService.read();
                break;
            }
            case '3': {
                int index;
                std::cout << "Id:"; std::cin >> index;

                unsigned int apartmentNumber;
                std::cout << "New apartment number:"; std::cin >> apartmentNumber;

                std::string billType;
                std::cout << "New bill type:"; std::cin >> billType;
                const char *billType_char = billType.c_str();

                unsigned int billTotal;
                std::cout << "New bill total:"; std::cin >> billTotal;

                Apartment newApartment(apartmentNumber, billType_char, billTotal);

                apartmentService.update(index - 1, newApartment);
                break;
            }
            case '4': {
                int position;
                std::cout << "Delete id:"; std::cin >> position;

                apartmentService.del(position - 1);
                break;
            }
            case '5': {
                unsigned int apartmentNumber;
                std::cout << "Delete all bills for this apartment number:"; std::cin >> apartmentNumber;

                apartmentService.deleteAllByApartmentNumber(apartmentNumber);
                break;
            }
            case '6': {
                unsigned int start, end;
                std::cout << "Delete all bills for all apartments from:"; std::cin >> start;
                std::cout << "To:"; std::cin >> end;

                apartmentService.deleteAllByApartmentInterval(start, end);
                break;
            }
            case '7': {
                std::string type;
                std::cout << "Delete all bills of this type:";
                std::cin >> type;
                const char *type_char = type.c_str();

                apartmentService.deleteAllByType(type_char);
                break;
            }
            case '8': {
                unsigned int apartmentNumber;
                std::cout << "Apartment number:";
                std::cin >> apartmentNumber;

                std::string type;
                std::cout << "Bill type:";
                std::cin >> type;
                const char *type_char = type.c_str();

                unsigned int newTotal;
                std::cout << "New bill total:";
                std::cin >> newTotal;

                apartmentService.updateByNumberAndType(apartmentNumber, type_char, newTotal);
                break;
            }
            case '9': {
                unsigned int apartmentNumber;
                std::cout << "Apartment number:";
                std::cin >> apartmentNumber;

                std::cout << apartmentService.showAllBillsForApartment(apartmentNumber);
                break;
            }
            case '0': {
                unsigned int aboveThis;
                std::cout << "Above this price:";
                std::cin >> aboveThis;

                std::cout << apartmentService.showAllAboveThisPrice(aboveThis);
                break;
            }
            case 'a': {
                unsigned int equalThis;
                std::cout << "Same price as:";
                std::cin >> equalThis;

                std::cout << apartmentService.showAllEqualThisPrice(equalThis);
                break;
            }
            case 'b': {
                std::string type;
                std::cout << "Determine bills sum for this type:";
                std::cin >> type;
                const char *type_char = type.c_str();

                std::cout << apartmentService.sumBillsOfType(type_char);
                break;
            }
            case 'c': {
                unsigned int apartmentNumber;
                std::cout << "Apartment number:";
                std::cin >> apartmentNumber;

                std::cout << apartmentService.highestBillOfApartment(apartmentNumber);
                break;
            }
            case 'd': {
                std::string type;
                std::cout << "Sort by this type:";
                std::cin >> type;
                const char *type_char = type.c_str();

                std::cout << apartmentService.sortByType(type_char);
                break;
            }
            case 'e': {
                std::string type;
                std::cout << "Filter by this type:";
                std::cin >> type;
                const char *type_char = type.c_str();

                apartmentService.filterByType(type_char);
                break;
            }
            case 'f': {
                unsigned int total;
                std::cout << "Fitler all bills that are under this total:";
                std::cin >> total;

                apartmentService.filterByTotal(total);
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