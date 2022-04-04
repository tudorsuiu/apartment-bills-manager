//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_REPOSITORY_H
#define LAB_78_TUDORSUIU_REPOSITORY_H


#include <ostream>
#include "../Domain/Entity.h"
#include "../Domain/Vector.h"

template<class T> class Repository {
private:
    Vector<T> entities;
public:
    Repository();
    ~Repository();
    void addEntity(T entity);
    Vector<T> getAll();
    T getEntity(int index);
    int getSize();

    friend std::ostream &operator<<(std::ostream &os, const Repository<T> &repository);
};

template<class T>
Repository<T>::Repository() {
}

template<class T>
Repository<T>::~Repository() = default;

template<class T>
void Repository<T>::addEntity(T entity) {
    this->entities.push_back(entity);
}

template<class T>
Vector<T> Repository<T>::getAll() {
    return entities;
}

template<class T>
T Repository<T>::getEntity(int index) {
    return entities.at(index);
}

template<class T>
int Repository<T>::getSize() {
    return this->entities.size();
}

template<class T>
std::ostream &operator<<(std::ostream &os, const Repository<T> &repository) {
    os << repository.entities;
    return os;
}

#endif //LAB_78_TUDORSUIU_REPOSITORY_H