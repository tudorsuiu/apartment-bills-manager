//
// Created by Tudor on 4/10/2022.
//

#ifndef LAB_78_TUDORSUIU_SERVICE_H
#define LAB_78_TUDORSUIU_SERVICE_H

#include <iostream>
#include "../Repository/Repository.h"

class Service {
private:
    Repository<ApartmentBill> repository;
    Vector<Vector<ApartmentBill>> undoList;
public:
    /**
     * Add entity to repository
     * @param entity: ApartmentBill object
     */
    void create(ApartmentBill entity);

    /**
     * Reads all apartment bills stored in repository
     * @return: Vector<ApartmentBill> - all apartment bills stored in repository
     */
    Vector<ApartmentBill> read();

    /**
     * Updates an apartment bill by given index from repository
     * @param index: int - Apartment bill location in repository
     * @param newEntity
     */
    void update(int index, ApartmentBill newEntity);

    /**
     * Delete an apartment bill from repository
     * @param index: int - Apartment bill location in repository
     */
    void del(int index);

    /**
     * Deletes all apartment bills for an given apartment number
     * @param apartmentNumber: unsigned int - apartment bill number
     */
    void deleteAllByApartmentNumber(unsigned int apartmentNumber);

    /**
     * Deletes all apartment bills from an interval of apartment numbers
     * @param start: unsigned int - from this apartment number
     * @param end: unsigned int - to this apartment number
     */
    void deleteAllByApartmentInterval(unsigned int start, unsigned int end);

    /**
     * Deletes all apartment bills that contain a specified type
     * @param type: const char* - apartment bill type
     */
    void deleteAllByType(const char* type);

    /**
     * Update by apartment number and type
     * @param apartmentNumber: unsigned int - apartment bill number
     * @param type: const char* - apartment bill type
     * @param total: unsigned int - new apartment bill total
     */
    void updateByNumberAndType(unsigned int apartmentNumber, const char* type, unsigned int total);

    /**
     * Show all bills for an apartment
     * @param apartmentNumber: unsigned int - apartment number
     * @return: Vector<ApartmentBill> - all bills for an apartment
     */
    Vector<ApartmentBill> showAllBillsForApartment(unsigned int apartmentNumber);

    /**
     * Show all bills above a specified price
     * @param aboveThis: unsigned int - specified price
     * @return: all bills that have a total greater than aboveThis
     */
    Vector<ApartmentBill> showAllAboveThisPrice(unsigned int aboveThis);

    /**
     * Show all bills equal to a specified price
     * @param equalThis: unsigned int - specified price
     * @return: all bills that are equal to equalThis
     */
    Vector<ApartmentBill> showAllEqualThisPrice(unsigned int equalThis);

    /**
     * Determine the sum of all bills of a specified type
     * @param type: const char* - specified type
     * @return: sum of all bills of a specified type
     */
    unsigned int sumBillsOfType(const char* type);

    /**
     * Determine the highest bill of an apartment
     * @param apartmentNumber: unsigned int - specified number
     * @return: the highest bill of an apartment
     */
    ApartmentBill highestBillOfApartment(unsigned int apartmentNumber);

    /**
     * Sort the bills of a specified type descending by total
     * @param type: const char* - specified type
     * @return: bills of a specified type descending by total
     */
    Vector<ApartmentBill> sortByType(const char* type);

    /**
     * Delete all apartment bills that do not respect the specified type
     * @param type: const char* - specified type
     */
    void filterByType(const char* type);

    /**
     * Delete all apartment bills that are not greater than the specified total
     * @param total: unsigned int - specified total
     */
    void filterByTotal(unsigned int total);

    /**
     * Bring the repository to the previous form.
     */
    void undo();
};


#endif //LAB_78_TUDORSUIU_SERVICE_H
