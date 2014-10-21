#pragma once

#include <string>
#include <map>

class GameObject;
class Component;
class gameObjectManager;

// GameObject and Component typedefs
typedef std::string go_type_name, goc_type_name;
typedef unsigned long int go_type_id;
typedef std::map<goc_type_name, Component*> Component_map;
typedef std::map<go_type_id, GameObject*> GameObject_map;
