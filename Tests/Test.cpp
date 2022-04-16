//
// Created by Tudor on 4/3/2022.
//

#include "Test.h"
#include "../Domain/ApartmentBill.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
#include <cassert>
#include <iostream>
#include <cstring>

void Test::getters() {
    ApartmentBill apartment;

    assert(apartment.getNumber() == 0);
    assert(apartment.getType() == nullptr);
    assert(apartment.getTotal() == 0);

    char* type = new char[10]{"asociatie"};

    ApartmentBill apartment1(32, type, 98);

    assert(apartment1.getNumber() == 32);
    assert(std::strcmp(apartment1.getType(), type) == 0);
    assert(apartment1.getTotal() == 98);

    delete[] type;
}

void Test::setters() {
    ApartmentBill apartment;

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
    Repository<ApartmentBill> repository;
    assert(repository.getSize() == 0);

    char* type = new char[10]{"asociatie"};
    ApartmentBill apartment(32, type, 98);

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

    ApartmentBill apartment(32, type, 98);
    ApartmentBill apartment1(56, type1, 100);

    service.create(apartment);
    assert(service.read()[0] == apartment);

    service.create(apartment1);
    assert(service.read()[1] == apartment1);

    service.del(1);
    assert(service.read().size() == 1);


    ApartmentBill newApartment(56, type1, 100);
    service.update(0, newApartment);
    assert(service.read()[0] == apartment1);

    service.del(0);
    assert(service.read().size() == 0);

    delete[] type;
    delete[] type1;
}

void Test::functionalities() {
    Service apartmentService;

    ApartmentBill a1(32, "gaz", 122);
    ApartmentBill a2(56, "electricitate", 124);
    ApartmentBill a3(12, "apa", 243);
    ApartmentBill a4(24, "internet", 139);
    ApartmentBill a5(24, "gaz", 197);
    ApartmentBill a6(56, "gaz", 239);
    ApartmentBill a7(12, "electricitate", 100);
    ApartmentBill a8(12, "internet", 135);
    ApartmentBill a9(32, "electricitate", 71);
    ApartmentBill a10(40, "electricitate", 249);
    ApartmentBill a11(43, "apa", 80);
    ApartmentBill a12(56, "internet", 65);

    apartmentService.create(a1);
    apartmentService.create(a2);
    apartmentService.create(a3);
    apartmentService.create(a4);
    apartmentService.create(a5);
    apartmentService.create(a6);
    apartmentService.create(a7);
    apartmentService.create(a8);
    apartmentService.create(a9);
    apartmentService.create(a10);
    apartmentService.create(a11);
    apartmentService.create(a12);

    // Deletes all apartment bills for an apartment.
    apartmentService.deleteAllByApartmentNumber(32);

    assert(apartmentService.read().size() == 10);
    assert(apartmentService.read()[0] == a2);
    assert(apartmentService.read()[1] == a3);
    assert(apartmentService.read()[2] == a4);
    assert(apartmentService.read()[3] == a5);
    assert(apartmentService.read()[4] == a6);
    assert(apartmentService.read()[5] == a7);
    assert(apartmentService.read()[6] == a8);
    assert(apartmentService.read()[7] == a10);
    assert(apartmentService.read()[8] == a11);
    assert(apartmentService.read()[9] == a12);

    // Deletes all apartment bills from an interval of apartments.
    apartmentService.deleteAllByApartmentInterval(38, 60);

    assert(apartmentService.read().size() == 5);
    assert(apartmentService.read()[0] == a3);
    assert(apartmentService.read()[1] == a4);
    assert(apartmentService.read()[2] == a5);
    assert(apartmentService.read()[3] == a7);
    assert(apartmentService.read()[4] == a8);

    // Deletes all apartment bills that contain a specified type.
    apartmentService.deleteAllByType("internet");

    assert(apartmentService.read().size() == 3);
    assert(apartmentService.read()[0] == a3);
    assert(apartmentService.read()[1] == a5);
    assert(apartmentService.read()[2] == a7);

    // Update by apartment number and type.
    apartmentService.create(a1);
    apartmentService.create(a2);
    apartmentService.create(a4);
    apartmentService.create(a6);
    apartmentService.create(a8);
    apartmentService.create(a9);
    apartmentService.create(a10);
    apartmentService.create(a11);
    apartmentService.create(a12);

    apartmentService.updateByNumberAndType(32, "gaz", 85);
    apartmentService.updateByNumberAndType(56, "electricitate", 98);
    apartmentService.updateByNumberAndType(43, "apa", 30);

    assert(apartmentService.read()[3] == ApartmentBill(32, "gaz", 85));
    assert(apartmentService.read()[4] == ApartmentBill(56, "electricitate", 98));
    assert(apartmentService.read()[10] == ApartmentBill(43, "apa", 30));

    // Show all bills for an apartment.
    Vector<ApartmentBill> resultApartment = apartmentService.showAllBillsForApartment(32);

    assert(resultApartment.size() == 2);
    assert(resultApartment[0] == ApartmentBill(32, "gaz", 85));
    assert(resultApartment[1] == ApartmentBill(32, "electricitate", 71));

    // Show all bills above a specified price.
    Vector<ApartmentBill> resultAbovePrice = apartmentService.showAllAboveThisPrice(130);

    assert(resultAbovePrice.size() == 6);
    assert(resultAbovePrice[0] == a3);
    assert(resultAbovePrice[1] == a5);
    assert(resultAbovePrice[2] == a4);
    assert(resultAbovePrice[3] == a6);
    assert(resultAbovePrice[4] == a8);
    assert(resultAbovePrice[5] == a10);

    // Show all bills equal to a specified price.
    Vector<ApartmentBill> resultEqualPrice = apartmentService.showAllEqualThisPrice(197);

    assert(resultEqualPrice.size() == 1);
    assert(resultEqualPrice[0] == a5);

    // Determine the sum of all bills of a specified type.
    unsigned int sum = apartmentService.sumBillsOfType("electricitate");
    assert(sum == 518);

    // Determine the highest bill of an apartment.
    ApartmentBill highest = apartmentService.highestBillOfApartment(12);
    assert(highest == a3);

    // Sort the bills of a specified type descending by total.
    Vector<ApartmentBill> sorted = apartmentService.sortByType("electricitate");

    assert(sorted.size() == 4);
    assert(sorted[0] == a10);
    assert(sorted[1] == a7);
    assert(sorted[2] == ApartmentBill(56, "electricitate", 98));
    assert(sorted[3] == a9);

    // Filter by type.
    apartmentService.filterByType("internet");

    assert(apartmentService.read().size() == 3);
    assert(apartmentService.read()[0] == a4);
    assert(apartmentService.read()[1] == a8);
    assert(apartmentService.read()[2] == a12);

    // Filter by total (under a specified price).
    apartmentService.create(a1);
    apartmentService.create(a2);
    apartmentService.create(a3);
    apartmentService.create(a5);
    apartmentService.create(a6);
    apartmentService.create(a7);
    apartmentService.create(a9);
    apartmentService.create(a10);
    apartmentService.create(a11);

    apartmentService.filterByTotal(100);

    assert(apartmentService.read().size() == 3);
    assert(apartmentService.read()[0] == a12);
    assert(apartmentService.read()[1] == a9);
    assert(apartmentService.read()[2] == a11);
}

void Test::undo() {
    Service apartmentService;

    ApartmentBill a1(32, "gaz", 122);
    ApartmentBill a2(56, "electricitate", 124);
    ApartmentBill a3(12, "apa", 243);
    ApartmentBill a4(24, "internet", 139);
    ApartmentBill a5(24, "gaz", 197);

    apartmentService.create(a1);
    apartmentService.create(a2);
    apartmentService.create(a3);
    apartmentService.create(a4);
    apartmentService.create(a5);

    // Deletes all apartment bills for an apartment.
    apartmentService.deleteAllByApartmentNumber(24);
    assert(apartmentService.read().size() == 3);
    apartmentService.undo();
    assert(apartmentService.read().size() == 5);

    // Deletes all apartment bills from an interval of apartments.
    apartmentService.deleteAllByApartmentInterval(10, 25);
    assert(apartmentService.read().size() == 2);
    apartmentService.undo();
    assert(apartmentService.read().size() == 5);

    // Deletes all apartment bills that contain a specified type.
    apartmentService.deleteAllByType("gaz");
    assert(apartmentService.read().size() == 3);
    apartmentService.undo();
    assert(apartmentService.read().size() == 5);

    // Update by apartment number and type.
    apartmentService.updateByNumberAndType(32, "gaz", 120);
    assert(apartmentService.read()[0] == ApartmentBill(32, "gaz", 120));
    apartmentService.undo();
    assert(apartmentService.read()[0] == a1);

    // Filter by type.
    apartmentService.filterByType("gaz");
    assert(apartmentService.read().size() == 2);
    apartmentService.undo();
    assert(apartmentService.read().size() == 5);


    // Filter by total (under a specified price).
    apartmentService.filterByTotal(150);
    assert(apartmentService.read().size() == 3);
    apartmentService.undo();
    assert(apartmentService.read().size() == 5);
}

void Test::all() {
    getters();
    setters();
    repository();
    service();
    functionalities();
    undo();
    std::cout << "All tests passed!" << '\n' << '\n';
}