#include <map>

class Component;

class GameObject
{
public:
    // Constructor
    GameObject(unsigned short);

    // Destructor
    ~GameObject();

private:
    // My id in the world
    unsigned short entity_id_;

    std::map<short, Component*> componentMap_;

};
