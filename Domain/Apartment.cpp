//
// Created by Tudor on 4/3/2022.
//

#include <iostream>
#include <cstring>
#include "Apartment.h"

Apartment::Apartment() {
    this->number = 0;
    this->type = nullptr;
    this->total = 0;
}

Apartment::Apartment(unsigned int apartmentNumber, const char* billType, unsigned int billTotal) {
    this->number = apartmentNumber;
    this->type = new char[strlen(billType) + 1];
    strcpy(this->type, billType);
    this->total = billTotal;
}

Apartment::Apartment(const Apartment &apartment) {
    this->number = apartment.number;
    this->type = new char[strlen(apartment.type) + 1];
    strcpy(this->type, apartment.type);
    this->total = apartment.total;
}

Apartment::~Apartment() {
    delete[] this->type;
    this->type = nullptr;
}

unsigned int Apartment::getNumber() const {
    return this->number;
}

void Apartment::setNumber(unsigned int number) {
    this->number = number;
}

char *Apartment::getType() const {
    return this->type;
}

void Apartment::setType(char *type) {
    delete[] this->type;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

unsigned int Apartment::getTotal() const {
    return this->total;
}

void Apartment::setTotal(unsigned int total) {
    this->total = total;
}

bool Apartment::operator<(const Apartment &apartment) const {
    if(strcmp(type, apartment.type) == 0) {
        if (total < apartment.total)
            return true;
        if (apartment.total < total)
            return false;
    }
    return false;
}

bool Apartment::operator>(const Apartment &apartment) const {
    return apartment < *this;
}

bool Apartment::operator<=(const Apartment &apartment) const {
    return !(apartment < *this);
}

bool Apartment::operator>=(const Apartment &apartment) const {
    return !(*this < apartment);
}

bool Apartment::operator==(const Apartment &entity) const {
    return this->number == entity.number && this->total == entity.total &&
    std::strcmp(this->type, entity.type) == 0;
}

bool Apartment::operator!=(const Apartment &entity) const {
    return !(*this == entity);
}

Apartment &Apartment::operator=(const Apartment &apartment) {
    delete[] this->type;
    this->total = apartment.total;
    this->number = apartment.number;
    this->type = new char[strlen(apartment.type) + 1];
    strcpy(this->type, apartment.type);
    return *this;
}

std::istream &operator>>(std::istream &is, Apartment &entity) {
    unsigned int apartmentNumber;
    std::cout << "Apartment number:"; is >> apartmentNumber;
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

std::ostream &operator<<(std::ostream &os, const Apartment &entity) {
    os << "Apartment number: " << entity.number << '\n' << "Bill type: " << entity.type << '\n' << "Bill total: " << entity.total << '\n';
    return os;
}
