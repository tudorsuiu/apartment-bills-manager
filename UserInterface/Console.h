//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_CONSOLE_H
#define LAB_78_TUDORSUIU_CONSOLE_H


#include <iostream>
#include "../Service/Service.h"

class Console {
private:
    Service apartmentService;
public:
    /**
     * Print our menu
     */
    void showMenu();

    /**
     * Runs menu
     */
    void runMenu();
};



#endif //LAB_78_TUDORSUIU_CONSOLE_H
