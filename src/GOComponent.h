#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers
class GameObject;

// Class type definitions
typedef std::string goc_type_id;

// Class GOComponent acts as an interface class for all the GameObject Components
// Derive components from this class and define pure virtual methods in them.
class GOComponent
{
public:
    // Constructor
    GOComponent() : parent_(0) { }

    // Virtual destructor
    virtual ~GOComponent() { }

    // Query components by family id. Interface method.
    virtual const goc_type_id& GetFamilyId() const = 0;

    // Query components by specific component id. Interface method.
    virtual const goc_type_id& GetComponentId() const = 0;

    // Set owner gameobject for this component
    void SetOwnerGO(GameObject* _go);

    // Query owner GameObject of this component
    GameObject* GetOwnerGO() const;

private:
    GameObject* parent_;

};

inline void GOComponent::SetOwnerGO(GameObject *_go)
{
    // If parent is already set, should we inform current parent before
    // we change the ownership of this object to another GameObject?
    parent_ = _go;
}

inline GameObject* GOComponent::GetOwnerGO() const
{
    return parent_;
}
