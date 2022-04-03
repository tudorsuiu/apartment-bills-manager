//
// Created by Tudor on 4/3/2022.
//

#include <iostream>
#include "Entity.h"

Entity::Entity() {
    this->id = 0;
}

Entity::Entity(int id) {
    this->id = id;
}

Entity::Entity(const Entity &entity) {
    this->id = entity.id;
}

Entity::~Entity() = default;

int Entity::getId() const {
    return this->id;
}

void Entity::setId(int idVal) {
    this->id = idVal;
}

bool Entity::operator==(const Entity &entity) const {
    return id == entity.id;
}

bool Entity::operator!=(const Entity &entity) const {
    return !(entity == *this);
}

std::istream &operator>>(std::istream &is, Entity &entity) {
    int idVal;
    std::cout << "id: ";
    is >> idVal;
    entity.id = idVal;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "id: " << entity.id;
    return os;
}

