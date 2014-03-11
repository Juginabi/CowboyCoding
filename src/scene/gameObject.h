#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers
#include "component.h"

// Typedefinitions for this class
typedef std::string go_type_id;

// gameObject (GO) class is the database key in gameObject/gameObjectComponent-map.
// GO acts as an entry point for all the components which define the gameObject.

class gameObject
{
public:
    // Constructor
    gameObject(go_type_id _myID);

    // Destructor
    ~gameObject();

    // Return gameObject id
    const go_type_id& getId() const;

    // Registers component to this gameobject. If GOC already exists, returns pointer to replaced GOC.
    component* attachComponent(component* _goc);

    // Request component from gameObject using GOC family id, returns NULL if no GOC found.
    component* getComponent(goc_type_id _id);

    // Removes component from gameObject.
    void detachComponent(goc_type_id _id);

    // Remove all components from gameObject
    void clearComponents();

private:
    // My id in the world
    go_type_id myID_;

    typedef std::map<goc_type_id, component*> component_map;
    // Map containing all the components this entity has registered into.
    component_map componentMap_;

};

inline const go_type_id& gameObject::getId() const
{
    return myID_;
}
