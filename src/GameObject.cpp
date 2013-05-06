#ifndef _NDEBUG
#include <iostream>
#endif

#include "GameObject.h"

GameObject::GameObject(go_type_id _myID) :
    myID_(_myID)
{
#ifndef _NDEBUG
    std::cout << "GameObject with ID: " << myID_ << " created!" << std::endl;
#endif
}

GameObject::~GameObject()
{
#ifndef _NDEBUG
    std::cout << "GameObject with ID: " << myID_ << " destroyed!" << std::endl;
#endif
}

GOComponent* GameObject::AttachComponent(GOComponent *_goc)
{
    gocomponent_map::iterator iter = componentMap_.find("Here family ID");
    if ( iter == componentMap_.end())
    {
        componentMap_.insert(std::pair<goc_family_id, GOComponent*>("Here family ID", _goc));
        return 0;
    }
    else
    {
        return iter->second;
    }
}

GOComponent* GameObject::GetComponent(goc_family_id _id)
{
    gocomponent_map::iterator iter = componentMap_.find(_id);
    if (iter == componentMap_.end())
    {
        return 0;
    }
    else
    {
        return iter->second;
    }
}

void GameObject::DetachComponent(goc_family_id _id)
{
    gocomponent_map::iterator iter = componentMap_.find(_id);
    if (iter != componentMap_.end())
    {
        // Remove component here
        GOComponent* goc =  iter->second;
        componentMap_.erase(iter);
        delete goc;
    }
}

void GameObject::clearGOComponents()
{
    gocomponent_map::iterator iter = componentMap_.begin();
    while (iter != componentMap_.end())
    {
        // Remove component here
        delete iter->second;
    }
    componentMap_.clear();
}
