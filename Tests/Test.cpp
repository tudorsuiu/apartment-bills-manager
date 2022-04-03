//
// Created by Tudor on 4/3/2022.
//

#include "Test.h"
#include "../Domain/Entity.h"
#include "../Repository/Repository.h"
#include <cassert>
#include <iostream>

void Test::constructors() {
    Entity entity = Entity(21);
    assert(entity.getId() == 21);

    Entity entityCopy = entity;
    assert(entityCopy.getId() == 21);
}

void Test::getters() {
    Entity entity = Entity(21);
    assert(entity.getId() == 21);

    Repository repository;
    Entity entity1 = Entity(1);
    Entity entity2 = Entity(2);
    Entity entity3 = Entity(3);
    repository.addEntity(entity1);
    repository.addEntity(entity2);
    repository.addEntity(entity3);

    assert(repository.getSize() == 3);
    assert(repository.getEntity(0).getId() == 1);
    assert(repository.getEntity(1).getId() == 2);
    assert(repository.getEntity(2).getId() == 3);
}

void Test::setters() {
    Entity entity;
    entity.setId(21);
    assert(entity.getId() == 21);
}

void Test::all() {
    this->constructors();
    this->getters();
    this->setters();
}
