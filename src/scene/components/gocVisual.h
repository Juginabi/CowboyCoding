#pragma once

#include "../../commonTypeDefs.h"

// Project specific headers and forward declarations
#include "../component.h"

#ifndef _NDEBUG
#include <iostream>
#endif

// Class GocVisual component is a family of components which make the entity visible
class GocVisual : public Component
{
    // Component interface
public:
    // Can be used to query family id of components inherited from this.
    const goc_type_id getFamilyId() const;

    // Destructor
    ~GocVisual();

    // GocVisual interface.
public:
    // Can be used to query specific type id of component inherited from this.
    virtual const goc_type_id getComponentId() const = 0;

    // This class introduces render method.
    virtual void render() const = 0;
};


inline const goc_type_id GocVisual::getFamilyId() const {
    return goc_type_id("GocVisual");
}

inline GocVisual::~GocVisual() {
#ifndef _NDEBUG
    std::cout << "GocVisual destructor" << std::endl;
#endif
}
