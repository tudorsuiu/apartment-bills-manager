//
// Created by Tudor on 4/3/2022.
//

#include "Test.h"
#include "../Domain/Apartment.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
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

void Test::repository() {
    Repository<Apartment> repository;
    assert(repository.getSize() == 0);

    char* type = new char[10]{"asociatie"};
    Apartment apartment(32, type, 98);

    repository.addEntity(apartment);
    assert(repository.getSize() == 1);

    repository.deleteEntity(32);
    assert(repository.getSize() == 0);

    delete[] type;
}

void Test::service() {
    Service service;
    assert(service.read().size() == 0);

    char* type = new char[10]{"asociatie"};
    char* type1 = new char[4]{"gaz"};

    Apartment apartment(32, type, 98);
    Apartment apartment1(56, type1, 100);

    service.create(32, type, 98);
    assert(service.read()[0] == apartment);

    service.create(56, type1, 100);
    assert(service.read()[1] == apartment1);

    service.del(1);
    assert(service.read().size() == 1);

    service.update(0, 56, type1, 100);
    assert(service.read()[0] == apartment1);

    service.del(0);
    assert(service.read().size() == 0);

    delete[] type;
    delete[] type1;
}

void Test::all() {
    getters();
    setters();
    repository();
    service();
    std::cout << "All tests passed!" << '\n' << '\n';
}
