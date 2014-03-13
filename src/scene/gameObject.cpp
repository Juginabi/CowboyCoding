#ifndef _NDEBUG
#include <iostream>
#endif

#include "gameObject.h"

gameObject::gameObject(go_type_id _myID) :
    myID_(_myID)
{
#ifndef _NDEBUG
    std::cout << "gameObject with ID: " << myID_ << " created!" << std::endl;
#endif
}

gameObject::~gameObject()
{
    this->clearComponents();
#ifndef _NDEBUG
    std::cout << "gameObject with ID: " << myID_ << " destroyed!" << std::endl;
#endif
}

component* gameObject::attachComponent(component *_goc)
{
    const goc_type_id familyId = _goc->getFamilyId();

    component_map::iterator iter = componentMap_.find(familyId);
    if ( iter == componentMap_.end())
    {
        componentMap_.insert(std::pair<goc_type_id, component*>(familyId, _goc));
#ifndef _NDEBUG
        std::cout << "component with ID: " << familyId << " created!" << std::endl;
#endif
        return 0;
    }
    else
    {
        component* oldComp = iter->second;
        iter->second = _goc;
#ifndef _NDEBUG
        std::cout << "Replacing component with ID: " << familyId << " created!" << std::endl;
#endif
        return oldComp;
    }
}

component* gameObject::getComponent(goc_type_id _id)
{
    component_map::iterator iter = componentMap_.find(_id);
    if (iter == componentMap_.end())
    {
        return 0;
    }
    else
    {
        return iter->second;
    }
}

void gameObject::detachComponent(goc_type_id _id)
{
    component_map::iterator iter = componentMap_.find(_id);
    if (iter != componentMap_.end())
    {
        // Remove component here
        component* goc = iter->second;
        componentMap_.erase(iter);
        delete goc;
    }
}

void gameObject::clearComponents()
{
    component_map::iterator iter = componentMap_.begin();
    while (iter != componentMap_.end())
    {
        // Remove component here
#ifndef _NDEBUG
        std::cout << "Removing component ID: " << iter->first << std::endl;
#endif
        delete iter->second;
        ++iter;
    }
    componentMap_.clear();
}
