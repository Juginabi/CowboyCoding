#include "World.h"
#include "GameObject.h"

unsigned short World::entity_id_ = 0;

World::World()
{
    // Constructor
}

World::~World()
{
    std::vector<GameObject*>::iterator it = GameObjectMap_.begin();
    while (it != GameObjectMap_.end())
    {
        delete (*it);
        it++;
    }
    //GameObjectMap_.clear();
}

GameObject* World::CreateGameObject()
{
    // Create entity here
    ushort freeId = entity_id_++;
    GameObject* GO = new GameObject(freeId);
    GameObjectMap_.push_back(GO);
    return GO;
}
