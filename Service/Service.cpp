//
// Created by Tudor on 4/10/2022.
//

#include "Service.h"

void Service::create(ApartmentBill entity) {
    undoList.push_back(repository.getAll());
    repository.addEntity(entity);
}

Vector<ApartmentBill> Service::read() {
    return repository.getAll();
}

void Service::update(int index, ApartmentBill newEntity) {
    undoList.push_back(repository.getAll());

    repository.updateEntity(index, newEntity);
}

void Service::del(int index) {
    undoList.push_back(repository.getAll());

    repository.deleteEntity(index);
}

void Service::deleteAllByApartmentNumber(unsigned int apartmentNumber) {
    undoList.push_back(repository.getAll());

    while(repository.getEntityPosByNumber(apartmentNumber) != -1) {
        repository.deleteEntity(repository.getEntityPosByNumber(apartmentNumber));
    }
}

void Service::deleteAllByApartmentInterval(unsigned int start, unsigned int end) {
    undoList.push_back(repository.getAll());

    for(unsigned int i = start; i <= end; i++) {
        while(repository.getEntityPosByNumber(i) != -1) {
            repository.deleteEntity(repository.getEntityPosByNumber(i));
        }
    }
}

void Service::deleteAllByType(const char* type) {
    undoList.push_back(repository.getAll());

    while(repository.getEntityPosByType(type) != -1) {
        repository.deleteEntity(repository.getEntityPosByType(type));
    }
}

void Service::updateByNumberAndType(unsigned int apartmentNumber, const char *type, unsigned int total) {
    undoList.push_back(repository.getAll());

    int position = repository.getEntityPosByNumberAndType(apartmentNumber, type);
    if(position != -1) {
        ApartmentBill newApartment = ApartmentBill(apartmentNumber, type, total);
        repository.updateEntity(position, newApartment);
    }
}

Vector<ApartmentBill> Service::showAllBillsForApartment(unsigned int apartmentNumber) {
    Vector<ApartmentBill> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getNumber() == apartmentNumber) {
            result.push_back(repository.getEntity(i));
        }
    }
    return result;
}

Vector<ApartmentBill> Service::showAllAboveThisPrice(unsigned int aboveThis) {
    Vector<ApartmentBill> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getTotal() > aboveThis) {
            result.push_back(repository.getEntity(i));
        }
    }
    return result;
}

Vector<ApartmentBill> Service::showAllEqualThisPrice(unsigned int equalThis) {
    Vector<ApartmentBill> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getTotal() == equalThis) {
            result.push_back(repository.getEntity(i));
        }
    }
    return result;
}

unsigned int Service::sumBillsOfType(const char *type) {
    unsigned int total = 0;
    for(int i = 0; i < repository.getSize(); i++) {
        if(std::strcmp(repository.getEntity(i).getType(), type) == 0) {
            total = total + repository.getEntity(i).getTotal();
        }
    }
    return total;
}

ApartmentBill Service::highestBillOfApartment(unsigned int apartmentNumber) {
    unsigned int maximumBillTotal = 0;
    ApartmentBill highestBill;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getNumber() == apartmentNumber &&
           repository.getEntity(i).getTotal() > maximumBillTotal) {
            maximumBillTotal = repository.getEntity(i).getTotal();
            highestBill = repository.getEntity(i);
        }
    }
    return highestBill;
}

Vector<ApartmentBill> Service::sortByType(const char *type) {
    Vector<ApartmentBill> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(std::strcmp(repository.getEntity(i).getType(), type) == 0) {
            result.push_back(repository.getEntity(i));
        }
    }
    for(int i = 0; i < result.size() - 1; i++) {
        for(int j = i + 1; j < result.size(); j++) {
            if(result[i].getTotal() < result[j].getTotal()) {
                ApartmentBill temp;
                temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    return result;
}


void Service::filterByType(const char *type) {
    undoList.push_back(repository.getAll());

    Vector<ApartmentBill> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(std::strcmp(repository.getEntity(i).getType(), type) == 0) {
            result.push_back(repository.getEntity(i));
        }
    }
    repository.setAll(result);
}

void Service::filterByTotal(unsigned int total) {
    undoList.push_back(repository.getAll());

    Vector<ApartmentBill> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getTotal() < total) {
            result.push_back(repository.getEntity(i));
        }
    }
    repository.setAll(result);
}

void Service::undo() {
    if(undoList.size() != 0) {
        repository.setAll(undoList.pop_back());
    }
    else {
        std::cout << "Undo list is empty!" << '\n';
    }
}
