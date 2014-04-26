#pragma once

// Project specific headers
#include "component.h"
#include "../commonTypeDefs.h"

// GameObject (GO) class is the database key in GameObject/GameObjectComponent-map.
// GO acts as an entry point for all the Components which define the GameObject.
class GameObject
{
public:
    // Constructor
    // Explicit, meaning no implicit type conversion can not be done.
    explicit GameObject(go_type_id _myID);

    // Destructor
    ~GameObject();

    // Return GameObject id
    const go_type_id& getId() const;

    // Registers Component to this gameobject. If GOC already exists, returns pointer to replaced GOC.
    ComponentPtr attachComponent(ComponentPtr _goc);

    // Request Component from GameObject using GOC family id, returns NULL if no GOC found.
    ComponentPtr getComponent(goc_type_id _id);

    // Removes Component from GameObject.
    void detachComponent(goc_type_id _id);

    // Remove all Components from GameObject
    void clearComponents();

private:
    // My id in the world
    go_type_id myID_;

    // Map containing all the Components this entity has registered into.
    Component_map ComponentMap_;
};

inline const go_type_id& GameObject::getId() const {
    return myID_;
}
