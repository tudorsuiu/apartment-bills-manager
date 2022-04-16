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
    void create(Apartment entity);
    Vector<Apartment> read();
    void update(int index, Apartment newEntity);
    void del(int index);

    void deleteAllByApartmentNumber(unsigned int apartmentNumber);
    void deleteAllByApartmentInterval(unsigned int start, unsigned int end);
    void deleteAllByType(const char* type);
    void updateByNumberAndType(unsigned int apartmentNumber, const char* type, unsigned int total);
    Vector<Apartment> showAllBillsForApartment(unsigned int apartmentNumber);
    Vector<Apartment> showAllAboveThisPrice(unsigned int aboveThis);
    Vector<Apartment> showAllEqualThisPrice(unsigned int equalThis);
    unsigned int sumBillsOfType(const char* type);
    Apartment highestBillOfApartment(unsigned int apartmentNumber);
    Vector<Apartment> sortByType(const char* type);
    void filterByType(const char* type);
    void filterByTotal(unsigned int total);
};


#endif //LAB_78_TUDORSUIU_SERVICE_H
