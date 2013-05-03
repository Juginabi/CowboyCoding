#ifndef _NDEBUG
#include <iostream>
#endif

#include "GameObject.h"

GameObject::GameObject(unsigned short _entity_id) :
    entity_id_(_entity_id)
{
#ifndef _NDEBUG
    std::cout << "GameObject with ID: " << entity_id_ << " created!" << std::endl;
#endif
}

GameObject::~GameObject()
{
#ifndef _NDEBUG
    std::cout << "GameObject with ID: " << entity_id_ << " destroyed!" << std::endl;
#endif
}

