#pragma once

#include <memory>
#include <string>
#include <map>

class GameObject;
class Component;

typedef std::shared_ptr<GameObject> GameObjectPtr;
typedef std::shared_ptr<Component> ComponentPtr;

// GameObject and Component typedefs
typedef std::string go_type_id, goc_type_id;
typedef std::map<goc_type_id, ComponentPtr> Component_map;
