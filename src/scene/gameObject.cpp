#ifndef _NDEBUG
#include <iostream>
#endif

#include "gameObject.h"

GameObject::GameObject(go_type_id _myID) :
    myID_(_myID)
{
#ifndef _NDEBUG
    std::cout << "GameObject with ID: " << myID_ << " created!" << std::endl;
#endif
}

GameObject::~GameObject()
{
    this->clearComponents();
#ifndef _NDEBUG
    std::cout << "GameObject with ID: " << myID_ << " destroyed!" << std::endl;
#endif
}

Component* GameObject::attachComponent(Component *_goc)
{
    const goc_type_id familyId = _goc->getFamilyId();

    Component_map::iterator iter = ComponentMap_.find(familyId);
    if ( iter == ComponentMap_.end())
    {
        ComponentMap_.insert(std::pair<goc_type_id, Component*>(familyId, _goc));
        _goc->setOwner(this);
#ifndef _NDEBUG
        std::cout << "Component with ID: " << familyId << " created!" << std::endl;
#endif
        return 0;
    }
    else
    {
        Component* oldComp = iter->second;
        iter->second = _goc;
#ifndef _NDEBUG
        std::cout << "Replacing Component with ID: " << familyId << " created!" << std::endl;
#endif
        return oldComp;
    }
}

Component* GameObject::getComponent(goc_type_id _id)
{
    Component_map::iterator iter = ComponentMap_.find(_id);
    if (iter == ComponentMap_.end())
    {
        return 0;
    }
    else
    {
        return iter->second;
    }
}

void GameObject::detachComponent(goc_type_id _id)
{
    Component_map::iterator iter = ComponentMap_.find(_id);
    if (iter != ComponentMap_.end())
    {
        // Remove Component here
        Component* goc = iter->second;
        ComponentMap_.erase(iter);
        delete goc;
    }
}

void GameObject::clearComponents()
{
    Component_map::iterator iter = ComponentMap_.begin();
    while (iter != ComponentMap_.end())
    {
        // Remove Component here
#ifndef _NDEBUG
        std::cout << "Removing Component ID: " << iter->first << std::endl;
#endif
        delete iter->second;
        ++iter;
    }
    ComponentMap_.clear();
}
