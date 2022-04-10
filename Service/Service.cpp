//
// Created by Tudor on 4/10/2022.
//

#include "Service.h"

void Service::create(unsigned int apartmentNumber, const char *billType,
                     unsigned int billTotal) {
    Apartment entity(apartmentNumber, billType, billTotal);
    repository.addEntity(entity);
}

Vector<Apartment> Service::read() {
    return repository.getAll();
}

void Service::update(int position, unsigned int newApartmentNumber,
                     char *newBillType, unsigned int newBillTotal) {
    Apartment newEntity(newApartmentNumber, newBillType, newBillTotal);
    repository.updateEntity(position, newEntity);
}

void Service::del(int position) {
    repository.deleteEntity(position);
}