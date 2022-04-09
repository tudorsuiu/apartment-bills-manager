//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_VECTOR_H
#define LAB_78_TUDORSUIU_VECTOR_H


#include <ostream>
#include "Apartment.h"

template<class T> class Vector {
private:
    int DEFAULT_CAPACITY = 10;
    T* _entities;
    int _capacity;
    int _size;
    void resize() {
        _capacity = _capacity + DEFAULT_CAPACITY;
        T* newEntities = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            newEntities[i] = _entities[i];
        }
        delete[] _entities;
        _entities = newEntities;
    }
public:
    Vector() {
        _size = 0;
        _capacity = DEFAULT_CAPACITY;
        _entities = new T[_capacity];
    }

    Vector(const Vector<T>& vector) {
        this->_capacity = vector._capacity;
        this->_size = vector._size;
        T* newEntities = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            newEntities[i] = vector._entities[i];
        }
        this->_entities = newEntities;
    }

    ~Vector() {
        delete[] this->_entities;
    }

    void push_back(T entity) {
        if(_size == _capacity){
            resize();
        }
        _entities[_size] = entity;
        _size++;
    }

    int size() const {
        return this->_size;
    }

    T at(int index) const {
        return this->_entities[index];
    }

    T operator[](int index) const {
        return this->_entities[index];
    }

    Vector<T> &operator=(const Vector<T> &vector) {
        this->size = vector._size;
        this->_capacity = vector._capacity;
        delete[] this->_entities;
        for(int i = 0; i < _size; i++) {
            this->_entities[i] = vector._entities[i];
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector<T> &vector) {
        for(int i = 0; i < vector._size; i++) {
            os << vector[i] << '\n';
        }
        return os;
    }
};

#endif //LAB_78_TUDORSUIU_VECTOR_H
