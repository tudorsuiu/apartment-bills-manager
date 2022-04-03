//
// Created by Tudor on 4/3/2022.
//

#include "Vector.h"

Vector::Vector() {
    _capacity = CAPACITY_BATCH_SIZE;
    _entities = new Entity[_capacity];
    _size = 0;
}

Vector::~Vector() {
    delete[] _entities;
}

void Vector::resize() {
    _capacity = _capacity + CAPACITY_BATCH_SIZE;
    Entity* newEntities = new Entity[_capacity];
    for (int i = 0; i < _size; i++) {
        newEntities[i] = _entities[i];
    }
    delete[] _entities;
    _entities = newEntities;
}

void Vector::push_back(Entity entity) {
    if(_size == _capacity){
        resize();
    }
    this->_entities[_size] = entity;
    _size++;
}

int Vector::size() const {
    return this->_size;
}

Entity Vector::operator[](int index) const{
    return this->_entities[index];
}

Entity Vector::at(int index) const {
    return this->_entities[index];
}

std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    for(int i = 0; i < vector._size; i++) {
        os << vector.at(i) << '\n';
    }
    return os;
}




