//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_VECTOR_H
#define LAB_78_TUDORSUIU_VECTOR_H


#include <ostream>
#include "Entity.h"

class Vector {
private:
    const int CAPACITY_BATCH_SIZE = 1024;
    Entity* _entities;
    int _capacity;
    int _size;
    void resize();
public:
    Vector();
    ~Vector();
    void push_back(Entity entity);
    int size() const;
    Entity at(int index) const;

    Entity operator[](int index) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector &vector);
};


#endif //LAB_78_TUDORSUIU_VECTOR_H
