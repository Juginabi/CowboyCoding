#ifndef _NDEBUG
#include <iostream>
#endif

#include "World.h"
#include "GameObject.h"
#include "IComponen.h"
#include "ExampleComponent.h"

unsigned short World::entity_id_ = 0;

World::World()
{
    // Constructor
}

World::~World()
{
    std::map<entityID, GameObject*>::iterator it = GameObjectMap_.begin();
    while (it != GameObjectMap_.end())
    {
        delete it->second;
        it++;
    }
    GameObjectMap_.clear();
}

GameObject* World::CreateGameObject()
{
    GameObject* GO = new GameObject(entity_id_++, this);
    GameObjectMap_.insert(std::pair<entityID, GameObject*>(entity_id_, GO));
    return GO;
}

void World::CreateComponent(entityID entity_id)
{
    std::map<entityID, std::vector<IComponent*> >::iterator vecIt = componentMap_.find(entity_id);
    if (vecIt == componentMap_.end())
    {
        IComponent* comp = new ExampleComponent();
        std::vector<IComponent*> vec;
        vec.push_back(comp);
        componentMap_.insert(std::pair<entityID, std::vector<IComponent*> >(entity_id, vec));
#ifndef _NDEBUG
        std::cout << "Component created for entity id: " << entity_id << std::endl;
#endif

    }
}
