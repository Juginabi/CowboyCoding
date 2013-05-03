#include <vector>
typedef unsigned short ushort;

class GameObject;

class World
{
public:
    // Default constructor
    World();

    // Destructor
    ~World();

    // Creates entity for this world
    GameObject* CreateGameObject();

private:
    // GameObject map
    std::vector<GameObject*> GameObjectMap_;

    // Next free entity ID for this world.
    static ushort entity_id_;

};
