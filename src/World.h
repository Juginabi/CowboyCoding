#pragma once

#include <map>
#include <vector>

typedef unsigned short entityID;

class GameObject;
class IComponent;

class World
{
public:
    // Default constructor
    World();

    // Destructor
    ~World();

    // Creates gameobject for this world
    GameObject* CreateGameObject();

private:
    friend class GameObject;
    // Register component for entity
    void CreateComponent(entityID entity_id);

    // GameObject map
    std::map<entityID, GameObject*> GameObjectMap_;

    // Components for entities
    std::map<entityID, std::vector<IComponent*> > componentMap_;

    // Next free entity ID for this world.
    static entityID entity_id_;

};
