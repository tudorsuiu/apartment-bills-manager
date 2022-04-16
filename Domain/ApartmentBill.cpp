//
// Created by Tudor on 4/3/2022.
//

#include <iostream>
#include <cstring>
#include "ApartmentBill.h"

ApartmentBill::ApartmentBill() {
    this->number = 0;
    this->type = nullptr;
    this->total = 0;
}

ApartmentBill::ApartmentBill(unsigned int apartmentNumber, const char* billType, unsigned int billTotal) {
    this->number = apartmentNumber;
    this->type = new char[strlen(billType) + 1];
    strcpy(this->type, billType);
    this->total = billTotal;
}

ApartmentBill::ApartmentBill(const ApartmentBill &entity) {
    this->number = entity.number;
    this->type = new char[strlen(entity.type) + 1];
    strcpy(this->type, entity.type);
    this->total = entity.total;
}

ApartmentBill::~ApartmentBill() {
    delete[] this->type;
    this->type = nullptr;
}

unsigned int ApartmentBill::getNumber() const {
    return this->number;
}

void ApartmentBill::setNumber(unsigned int number) {
    this->number = number;
}

char *ApartmentBill::getType() const {
    return this->type;
}

void ApartmentBill::setType(char *type) {
    delete[] this->type;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

unsigned int ApartmentBill::getTotal() const {
    return this->total;
}

void ApartmentBill::setTotal(unsigned int total) {
    this->total = total;
}

bool ApartmentBill::operator<(const ApartmentBill &entity) const {
    if(strcmp(type, entity.type) == 0) {
        if (total < entity.total)
            return true;
        if (entity.total < total)
            return false;
    }
    return false;
}

bool ApartmentBill::operator>(const ApartmentBill &entity) const {
    return entity < *this;
}

bool ApartmentBill::operator<=(const ApartmentBill &entity) const {
    return !(entity < *this);
}

bool ApartmentBill::operator>=(const ApartmentBill &entity) const {
    return !(*this < entity);
}

bool ApartmentBill::operator==(const ApartmentBill &entity) const {
    return this->number == entity.number && this->total == entity.total &&
    std::strcmp(this->type, entity.type) == 0;
}

bool ApartmentBill::operator!=(const ApartmentBill &entity) const {
    return !(*this == entity);
}

ApartmentBill &ApartmentBill::operator=(const ApartmentBill &entity) {
    delete[] this->type;
    this->total = entity.total;
    this->number = entity.number;
    this->type = new char[strlen(entity.type) + 1];
    strcpy(this->type, entity.type);
    return *this;
}

std::istream &operator>>(std::istream &is, ApartmentBill &entity) {
    unsigned int apartmentNumber;
    std::cout << "ApartmentBill number:"; is >> apartmentNumber;
    entity.number = apartmentNumber;

    char *billType = new char[15];
    std::cout << "Bill type:"; is >> billType;
    delete[] entity.type;
    entity.type = new char[strlen(billType) + 1];
    strcpy(entity.type, billType);

    unsigned int billTotal;
    std::cout << "Bill total:"; is >> billTotal;
    entity.total = billTotal;

    delete[] billType;

    return is;
}

std::ostream &operator<<(std::ostream &os, const ApartmentBill &entity) {
    os << "ApartmentBill number: " << entity.number << '\n' << "Bill type: " << entity.type << '\n' << "Bill total: " << entity.total << '\n';
    return os;
}
