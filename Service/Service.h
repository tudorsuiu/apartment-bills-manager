//
// Created by Tudor on 4/10/2022.
//

#ifndef LAB_78_TUDORSUIU_SERVICE_H
#define LAB_78_TUDORSUIU_SERVICE_H

#include <iostream>
#include "../Repository/Repository.h"

class Service {
private:
    Repository<Apartment> repository;
public:
    void create(unsigned int apartmentNumber, const char* billType, unsigned int billTotal);
    Vector<Apartment> read();
    void update(int position, unsigned int newApartmentNumber, char* newBillType, unsigned int newBillTotal);
    void del(int position);
};


#endif //LAB_78_TUDORSUIU_SERVICE_H
