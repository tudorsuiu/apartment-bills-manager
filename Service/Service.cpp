//
// Created by Tudor on 4/10/2022.
//

#include "Service.h"

void Service::create(Apartment entity) {
    repository.addEntity(entity);
}

Vector<Apartment> Service::read() {
    return repository.getAll();
}

void Service::update(int index, Apartment newEntity) {
    repository.updateEntity(index, newEntity);
}

void Service::del(int index) {
    repository.deleteEntity(index);
}

void Service::deleteAllByApartmentNumber(unsigned int apartmentNumber) {
    while(repository.getEntityPosByNumber(apartmentNumber) != -1) {
        repository.deleteEntity(repository.getEntityPosByNumber(apartmentNumber));
    }
}

void Service::deleteAllByApartmentInterval(unsigned int start, unsigned int end) {
    for(unsigned int i = start; i <= end; i++) {
        while(repository.getEntityPosByNumber(i) != -1) {
            repository.deleteEntity(repository.getEntityPosByNumber(i));
        }
    }
}

void Service::deleteAllByType(const char* type) {
    while(repository.getEntityPosByType(type) != -1) {
        repository.deleteEntity(repository.getEntityPosByType(type));
    }
}

void Service::updateByNumberAndType(unsigned int apartmentNumber, const char *type, unsigned int total) {
    int position = repository.getEntityPosByNumberAndType(apartmentNumber, type);
    if(position != -1) {
        Apartment newApartment = Apartment(apartmentNumber, type, total);
        repository.updateEntity(position, newApartment);
    }
}

Vector<Apartment> Service::showAllBillsForApartment(unsigned int apartmentNumber) {
    Vector<Apartment> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getNumber() == apartmentNumber) {
            result.push_back(repository.getEntity(i));
        }
    }
    return result;
}

Vector<Apartment> Service::showAllAboveThisPrice(unsigned int aboveThis) {
    Vector<Apartment> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getTotal() > aboveThis) {
            result.push_back(repository.getEntity(i));
        }
    }
    return result;
}

Vector<Apartment> Service::showAllEqualThisPrice(unsigned int equalThis) {
    Vector<Apartment> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getTotal() > equalThis) {
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

Apartment Service::highestBillOfApartment(unsigned int apartmentNumber) {
    unsigned int maximumBillTotal = 0;
    Apartment highestBill;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getNumber() == apartmentNumber &&
           repository.getEntity(i).getTotal() > maximumBillTotal) {
            maximumBillTotal = repository.getEntity(i).getTotal();
            highestBill = repository.getEntity(i);
        }
    }
    return highestBill;
}

Vector<Apartment> Service::sortByType(const char *type) {
    Vector<Apartment> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(std::strcmp(repository.getEntity(i).getType(), type) == 0) {
            result.push_back(repository.getEntity(i));
        }
    }
    for(int i = 0; i < result.size() - 1; i++) {
        for(int j = i + 1; j < result.size(); j++) {
            if(result[i].getTotal() < result[j].getTotal()) {
                Apartment temp;
                temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    std::cout << result;
    return result;
}


void Service::filterByType(const char *type) {
    Vector<Apartment> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(std::strcmp(repository.getEntity(i).getType(), type) == 0) {
            result.push_back(repository.getEntity(i));
        }
    }
    repository.setAll(result);
}

void Service::filterByTotal(unsigned int total) {
    Vector<Apartment> result;
    for(int i = 0; i < repository.getSize(); i++) {
        if(repository.getEntity(i).getTotal() < total) {
            result.push_back(repository.getEntity(i));
        }
    }
    repository.setAll(result);
}