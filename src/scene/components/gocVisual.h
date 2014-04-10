#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers and forward declarations
#include "../component.h"

// Class type definitions
typedef std::string goc_type_id;

// Class gocVisual component is a family of components which make the entity visible
class gocVisual : public component
{
    // Component interface
public:
    const goc_type_id getFamilyId() const;

    // gocVisual interface.
public:
    virtual const goc_type_id getComponentId() const = 0;

    // This class introduces render method.
    virtual void render() const = 0;
};


inline const goc_type_id gocVisual::getFamilyId() const
{
    return goc_type_id("gocVisual");
}
