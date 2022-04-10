//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_REPOSITORY_H
#define LAB_78_TUDORSUIU_REPOSITORY_H


#include <ostream>
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

    T getEntity(int index) {
        return entities.at(index);
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