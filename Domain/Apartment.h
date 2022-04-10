//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_APARTMENT_H
#define LAB_78_TUDORSUIU_APARTMENT_H


#include <ostream>

class Apartment {
private:
    unsigned int number;
    char* type;
    unsigned int total;
public:
    Apartment();
    Apartment(unsigned int apartmentNumber, const char* type, unsigned int total);
    Apartment(const Apartment &entity);
    ~Apartment();

    unsigned int getNumber() const;
    void setNumber(unsigned int number);
    char *getType() const;
    void setType(char *type);
    unsigned int getTotal() const;
    void setTotal(unsigned int total);

    Apartment& operator=(const Apartment& apartment);

    bool operator==(const Apartment &entity) const;
    bool operator!=(const Apartment &entity) const;

    friend std::istream &operator>>(std::istream &is, Apartment &entity);
    friend std::ostream &operator<<(std::ostream &os, const Apartment &entity);
};


#endif //LAB_78_TUDORSUIU_APARTMENT_H
