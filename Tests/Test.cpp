//
// Created by Tudor on 4/3/2022.
//

#include "Test.h"
#include "../Domain/Apartment.h"
#include <cassert>
#include <iostream>
#include <cstring>

void Test::getters() {
    Apartment apartment;

    assert(apartment.getNumber() == 0);
    assert(apartment.getType() == nullptr);
    assert(apartment.getTotal() == 0);

    char* type = new char[10]{"asociatie"};

    Apartment apartment1(32, type, 98);

    assert(apartment1.getNumber() == 32);
    assert(std::strcmp(apartment1.getType(), type) == 0);
    assert(apartment1.getTotal() == 98);

    delete[] type;
}

void Test::setters() {
    Apartment apartment;

    char* type = new char[4]{"gaz"};

    apartment.setNumber(32);
    apartment.setType(type);
    apartment.setTotal(98);

    assert(apartment.getNumber() == 32);
    assert(std::strcmp(apartment.getType(), type) == 0);
    assert(apartment.getTotal() == 98);

    delete[] type;
}

void Test::all() {
    getters();
    setters();
    std::cout << "All tests passed!";
}
