//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_REPOSITORY_H
#define LAB_78_TUDORSUIU_REPOSITORY_H


#include <ostream>
#include <cstring>
#include "../Domain/ApartmentBill.h"
#include "../Domain/Vector.h"

template<class T> class Repository {
private:
    Vector<T> entities;
public:
    /**
     * Constructor
     */
    Repository() {
        this->entities = Vector<T>();
    }

    /**
     * Copy-constructor
     * @param repository: Repository object
     */
    Repository(const Repository<T> &repository) {
        this->entities = repository.entities;
    }

    /**
     * Destructor
     */
    ~Repository() = default;

    /**
     * Add entity to repository
     * @param entity: T class object
     */
    void addEntity(T entity) {
        this->entities.push_back(entity);
    }

    /**
     * Update an entity from repository
     * @param index: int - entity location in repository
     * @param newEntity: T class object
     */
    void updateEntity(int index, T newEntity) {
        entities.replace(index, newEntity);
    }

    /**
     * Delete an entity from repository
     * @param index: int - entity location in repository
     */
    void deleteEntity(int index) {
        entities.remove(index);
    }

    /**
     * Get all entities and returns them
     * @return: Vector<class T> - all entities stored in repository
     */
    Vector<T> getAll() {
        return this->entities;
    }

    /**
     * Change all entities from repository
     * @param newEntities: Vector<class T> - new entities
     */
    void setAll(Vector<T> newEntities) {
        this->entities = newEntities;
    }

    /**
     * Entity getter
     * @param index: int - entity location in repository
     * @return: class T - entity
     */
    T getEntity(int index) {
        return entities.at(index);
    }

    /**
     * Size getter
     * @return: int - repository size
     */
    int getSize() {
        return this->entities.size();
    }

    /**
     * Entity index getter by apartment bill number
     * @param apartmentNumber: unsigned int - apartment bill number
     * @return: int - index of the first entity with the specified apartment bill number
     */
    int getEntityPosByNumber(unsigned int apartmentNumber) {
        for(int i = 0; i < entities.size(); i++) {
            if(entities[i].getNumber() == apartmentNumber) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Entity index getter by apartment bill type
     * @param type: const char* - apartment bill type
     * @return: int - index of the first entity with the specified apartment bill type
     */
    int getEntityPosByType(const char* type) {
        for(int i = 0; i < entities.size(); i++) {
            if(std::strcmp(entities[i].getType(), type) == 0) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Entity index getter by apartment bill number and type
     * @param apartmentNumber: unsigned int - apartment bill number
     * @param type: const char* - apartment bill type
     * @return: index of the first entity with the specified apartment bill number and type
     */
    int getEntityPosByNumberAndType(unsigned int apartmentNumber, const char* type) {
        for(int i = 0; i < entities.size(); i++) {
            if(std::strcmp(entities[i].getType(), type) == 0 && entities[i].getNumber() == apartmentNumber) {
                return i;
            }
        }
        return -1;
    }

    friend std::ostream &operator<<(std::ostream &os, const Repository<T> &repository) {
        os << repository.entities;
        return os;
    }
};

#endif //LAB_78_TUDORSUIU_REPOSITORY_H