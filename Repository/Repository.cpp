//
// Created by Tudor on 4/3/2022.
//

#include "Repository.h"

Repository::Repository() {

}

Repository::~Repository() = default;

void Repository::addEntity(Entity entity) {
    this->entities.push_back(entity);
}

Vector Repository::getAll() {
    return entities;
}

Entity Repository::getEntity(int index) {
    return entities.at(index);
}

int Repository::getSize() {
    return this->entities.size();
}

std::ostream &operator<<(std::ostream &os, const Repository &repository) {
    os << repository.entities;
    return os;
}
