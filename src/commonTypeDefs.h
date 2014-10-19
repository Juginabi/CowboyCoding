#pragma once

#include <memory>
#include <string>
#include <map>

class GameObject;
class Component;
class gameObjectManager;

typedef std::shared_ptr<GameObject> GameObjectPtr;
typedef std::shared_ptr<Component> ComponentPtr;
typedef std::shared_ptr<gameObjectManager> goManagerPtr;

// GameObject and Component typedefs
typedef std::string go_type_name, goc_type_name;
typedef unsigned long int go_type_id;
typedef std::map<goc_type_name, ComponentPtr> Component_map;
typedef std::map<go_type_id, GameObjectPtr> GameObject_map;
