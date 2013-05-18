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
	this->clearGOComponents();
#ifndef _NDEBUG
    std::cout << "GameObject with ID: " << myID_ << " destroyed!" << std::endl;
#endif
}

GOComponent* GameObject::AttachComponent(GOComponent *_goc)
{
    const goc_type_id familyId = _goc->GetFamilyId();

    gocomponent_map::iterator iter = componentMap_.find(familyId);
    if ( iter == componentMap_.end())
    {
        componentMap_.insert(std::pair<goc_type_id, GOComponent*>(familyId, _goc));
		#ifndef _NDEBUG
            std::cout << "GOComponent with ID: " << familyId << " created!" << std::endl;
		#endif
        return 0;
    }
    else
    {
        return iter->second;
    }
}

GOComponent* GameObject::GetComponent(goc_type_id _id)
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

void GameObject::DetachComponent(goc_type_id _id)
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
		#ifndef _NDEBUG
			std::cout << "Removing GOComponent ID: " << iter->first << std::endl;
		#endif
        delete iter->second;
		++iter;
    }
    componentMap_.clear();
}
