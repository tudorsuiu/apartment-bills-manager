//
// Created by Tudor on 4/3/2022.
//

#ifndef LAB_78_TUDORSUIU_ENTITY_H
#define LAB_78_TUDORSUIU_ENTITY_H


#include <ostream>

class Entity {
private:
    int id;
public:
    Entity();
    Entity(int idVal);
    Entity(const Entity &entity);
    ~Entity();
    int getId() const;
    void setId(int id);

    bool operator==(const Entity &entity) const;
    bool operator!=(const Entity &entity) const;

    friend std::istream &operator>>(std::istream &is, Entity &entity);
    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);
};


#endif //LAB_78_TUDORSUIU_ENTITY_H
