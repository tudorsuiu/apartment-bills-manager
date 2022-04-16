//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_REPOSITORY_H
#define LAB_78_TUDORSUIU_REPOSITORY_H


#include <ostream>
#include <cstring>
#include "../Domain/Apartment.h"
#include "../Domain/Vector.h"

template<class T> class Repository {
private:
    Vector<T> entities;
public:
    Repository() {
        this->entities = Vector<T>();
    }

    Repository(const Repository<T> &repository) {
        this->entities = repository.entities;
    }

    ~Repository() = default;

    void addEntity(T entity) {
        this->entities.push_back(entity);
    }

    T readEntity(int position) {
        return this->entities[position];
    }

    void updateEntity(int position, T newEntity) {
        entities.replace(position, newEntity);
    }

    void deleteEntity(int position) {
        entities.remove(position);
    }

    Vector<T> getAll() {
        return this->entities;
    }

    void setAll(Vector<T> newEntities) {
        this->entities = newEntities;
    }

    T getEntity(int index) {
        return entities.at(index);
    }

    int getEntityPosByNumber(unsigned int apartmentNumber) {
        for(int i = 0; i < entities.size(); i++) {
            if(entities[i].getNumber() == apartmentNumber) {
                return i;
            }
        }
        return -1;
    }

    int getEntityPosByType(const char* type) {
        for(int i = 0; i < entities.size(); i++) {
            if(std::strcmp(entities[i].getType(), type) == 0) {
                return i;
            }
        }
        return -1;
    }

    int getEntityPosByTotal(unsigned int total) {
        for(int i = 0; i < entities.size(); i++) {
            if(entities[i].getTotal() == total) {
                return i;
            }
        }
        return -1;
    }

    int getEntityPosByNumberAndType(unsigned int apartmentNumber, const char* type) {
        for(int i = 0; i < entities.size(); i++) {
            if(std::strcmp(entities[i].getType(), type) == 0 && entities[i].getNumber() == apartmentNumber) {
                return i;
            }
        }
        return -1;
    }

    int getSize() {
        return this->entities.size();
    }

    friend std::ostream &operator<<(std::ostream &os, const Repository<T> &repository) {
        os << repository.entities;
        return os;
    }
};

#endif //LAB_78_TUDORSUIU_REPOSITORY_H