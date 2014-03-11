#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers and forward declarations
class gameObject;

// Class type definitions
typedef std::string goc_type_id;

// Class component acts as an interface class for all the GameObject Components
// Derive components from this class and define pure virtual methods in them.
class component
{
public:
    // Constructor
    component() : parent_(0) { }

    // Virtual destructor
    virtual ~component() { }

    // Query components by family id. Interface method.
    virtual const goc_type_id getFamilyId() const = 0;

    // Query components by specific component id. Interface method.
    virtual const goc_type_id getComponentId() const = 0;

    // Set owner gameobject for this component
    void setOwner(gameObject* _go);

    // Query owner GameObject of this component
    gameObject* getOwner() const;

private:
    gameObject* parent_;

};

inline void component::setOwner(gameObject *_go)
{
    // If parent is already set, should we inform current parent before
    // we change the ownership of this object to another GameObject?
    parent_ = _go;
}

inline gameObject* component::getOwner() const
{
    return parent_;
}
