//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_VECTOR_H
#define LAB_78_TUDORSUIU_VECTOR_H


#include <ostream>
#include "Entity.h"

template<class T> class Vector {
private:
    int CAPACITY_BATCH_SIZE = 1024;
    T* _entities;
    int _capacity{};
    int _size{};
    void resize();
public:
    Vector();
    Vector(const Vector<T>& vector);
    ~Vector();
    void push_back(T entity);
    int size() const;
    T at(int index) const;

    T operator[](int index) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector<T> &vector) {
        for(int i = 0; i < vector._size; i++) {
            os << vector[i] << '\n';
        }
        return os;
    }
};

template<class T>
Vector<T>::Vector() {
    _capacity = CAPACITY_BATCH_SIZE;
    _entities = new T[_capacity];
    _size = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T>& vector) {
    this->_capacity = vector._capacity;
    this->_size = vector._size;
    auto* newEntities = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        newEntities[i] = vector._entities[i];
    }
    this->_entities = newEntities;
}


template<class T>
Vector<T>::~Vector() {
    delete[] _entities;
}

template<class T>
void Vector<T>::resize() {
    _capacity = _capacity + CAPACITY_BATCH_SIZE;
    auto* newEntities = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        newEntities[i] = _entities[i];
    }
    delete[] _entities;
    _entities = newEntities;
}

template<class T>
void Vector<T>::push_back(T entity) {
    if(_size == _capacity){
        resize();
    }
    _entities[_size] = entity;
    _size++;
}

template<class T>
int Vector<T>::size() const {
    return this->_size;
}

template<class T>
T Vector<T>::operator[](int index) const{
    return this->_entities[index];
}

template<class T>
T Vector<T>::at(int index) const {
    return this->_entities[index];
}

#endif //LAB_78_TUDORSUIU_VECTOR_H
