#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers
#include "GOComponent.h"

// Typedefinitions for this class
typedef std::string go_type_id;

// GameObject (GO) class is the database key in GameObject/GameObjectComponent-map.
// GO acts as an entry point for all the components which define the GameObject.

class GameObject
{
public:
    // Constructor
    GameObject(go_type_id _myID);

    // Destructor
    ~GameObject();

    // Return gameObject id
    const go_type_id& GetId() const;

    // Registers GOComponent to this gameobject. If GOC already exists, returns pointer to replaced GOC.
    GOComponent* AttachComponent(GOComponent* _goc);

    // Request GOComponent from gameObject using GOC family id, returns NULL if no GOC found.
    GOComponent* GetComponent(goc_type_id _id);

    // Removes GOComponent from GameObject.
    void DetachComponent(goc_type_id _id);

    // Remove all GOComponents from GameObject
    void clearGOComponents();

private:
    // My id in the world
    go_type_id myID_;

    typedef std::map<goc_type_id, GOComponent*> gocomponent_map;
    // Map containing all the components this entity has registered into.
    gocomponent_map componentMap_;

};

inline const go_type_id& GameObject::GetId() const
{
    return myID_;
}
