#ifndef _NDEBUG
#include <iostream>
#endif

#include <memory>
#include "gameObject.h"

GameObject::GameObject(go_type_id _myID) :
    myID_(_myID) {
#ifndef _NDEBUG
    std::cout << "[GameObject] with ID: " << myID_ << " created!" << std::endl;
#endif
}

GameObject::~GameObject() {
    clearComponents();
#ifndef _NDEBUG
    std::cout << "[GameObject] with ID: " << myID_ << " destroyed!" << std::endl;
#endif
}

ComponentPtr GameObject::attachComponent(ComponentPtr _goc) {
    const goc_type_id familyId = _goc->getFamilyId();
    const goc_type_id componentId = _goc->getComponentId();

    Component_map::iterator iter = ComponentMap_.find(familyId);
    if ( iter == ComponentMap_.end() ) {
        ComponentMap_.insert(std::pair<goc_type_id, ComponentPtr>(familyId, _goc));
        _goc->setOwner(this);
#ifndef _NDEBUG
        std::cout << "[GameObject] Component with ID: " << familyId << "(" << componentId << ")" << " attached!" << std::endl;
#endif
        return 0;
    }
    else {
        ComponentPtr oldComp = iter->second;
        iter->second = _goc;
#ifndef _NDEBUG
        std::cout << "[GameObject] Replacing Component with ID: " << familyId << "(" << componentId << ")" << std::endl;
#endif
        return oldComp;
    }
}

ComponentPtr GameObject::getComponent(goc_type_id _id) {
    // Locate goc type and return it. If not found return 0.
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

void GameObject::detachComponent(goc_type_id _id) {
    // Find goc type and erase it
    Component_map::iterator iter = ComponentMap_.find(_id);
    if (iter != ComponentMap_.end())
    {
        // Remove Component here
        ComponentMap_.erase(iter);
    }
}

void GameObject::clearComponents() {
    // smart pointer frees the memory properly
    ComponentMap_.clear();
}
