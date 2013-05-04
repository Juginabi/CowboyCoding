#ifndef _NDEBUG
#include <iostream>
#endif

#include "GameObject.h"
#include "World.h"

GameObject::GameObject(entityID _entity_id, World *_world) :
    entity_id_(_entity_id),
    world_(_world)
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

void GameObject::CreateComponent()
{
    world_->CreateComponent(entity_id_);
}
