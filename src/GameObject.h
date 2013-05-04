#pragma once

#include <map>

typedef unsigned short entityID;
class Component;
class World;

class GameObject
{
public:
    // Constructor
    GameObject(entityID, World*);

    // Destructor
    ~GameObject();

    // Register component for this entity
    void CreateComponent();

private:
    // My id in the world
    unsigned short entity_id_;

    // Owner world
    World* world_;

    // Map containing all the components this entity has registered into.
    //std::map<unsigned short, Component*> componentMap_;

};
