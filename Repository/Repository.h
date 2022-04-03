//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_REPOSITORY_H
#define LAB_78_TUDORSUIU_REPOSITORY_H


#include <ostream>
#include "../Domain/Entity.h"
#include "../Domain/Vector.h"

class Repository {
private:
    Vector entities;
public:
    Repository();
    ~Repository();
    void addEntity(Entity entity);
    Vector getAll();
    Entity getEntity(int index);
    int getSize();

    friend std::ostream &
    operator<<(std::ostream &os, const Repository &repository);
};


#endif //LAB_78_TUDORSUIU_REPOSITORY_H
