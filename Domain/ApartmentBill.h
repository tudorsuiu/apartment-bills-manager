//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_APARTMENTBILL_H
#define LAB_78_TUDORSUIU_APARTMENTBILL_H


#include <ostream>

class ApartmentBill {
private:
    unsigned int number;
    char* type;
    unsigned int total;
public:
    /**
     * Constructor
     */
    ApartmentBill();

    /**
     * Constructor with 3 parameters
     * @param apartmentNumber: new apartment number
     * @param type: new type
     * @param total: new total
     */
    ApartmentBill(unsigned int apartmentNumber, const char* type, unsigned int total);

    /**
     * Copy-constructor
     * @param entity: entity to copy
     */
    ApartmentBill(const ApartmentBill &entity);

    /**
     * Destructor
     */
    ~ApartmentBill();

    /**
     * Apartment bill number getter
     * @return: unsigned int - apartment number
     */
    unsigned int getNumber() const;

    /**
     * Apartment bill number setter
     * @param number: unsigned int - new apartment number
     */
    void setNumber(unsigned int number);

    /**
     * Apartment bill type getter
     * @return: char* - apartment bill type
     */
    char *getType() const;

    /**
     * Apartment bill type setter
     * @param type: char* - new apartment bill type
     */
    void setType(char *type);

    /**
     * Apartment bill total getter
     * @return: unsigned int - apartment bill total
     */
    unsigned int getTotal() const;

    /**
     * Apartment bill total setter
     * @param total: unsigned int - new apartment bill total
     */
    void setTotal(unsigned int total);

    ApartmentBill& operator=(const ApartmentBill& entity);

    bool operator<(const ApartmentBill &entity) const;
    bool operator>(const ApartmentBill &entity) const;
    bool operator<=(const ApartmentBill &entity) const;
    bool operator>=(const ApartmentBill &entity) const;
    bool operator==(const ApartmentBill &entity) const;
    bool operator!=(const ApartmentBill &entity) const;

    friend std::istream &operator>>(std::istream &is, ApartmentBill &entity);
    friend std::ostream &operator<<(std::ostream &os, const ApartmentBill &entity);
};


#endif //LAB_78_TUDORSUIU_APARTMENTBILL_H
