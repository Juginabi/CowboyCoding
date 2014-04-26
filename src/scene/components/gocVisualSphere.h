#pragma once

#include "../../commonTypeDefs.h"

#ifndef _NDEBUG
    #include <iostream>
#endif

// Project specific headers and forward declarations
#include "gocVisual.h"

class GocVisualSphere : public GocVisual {
    // GocVisual interface
public:
    // Destructor
    ~GocVisualSphere();

    // Can be used to query family id of components inherited from this.
    const goc_type_id getComponentId() const { return goc_type_id("GocVisualSphere"); }

    // This method renders the entity visual on screen.
    void render() const;
};

inline GocVisualSphere::~GocVisualSphere() {
#ifndef _NDEBUG
    std::cout << "GocVisualSphere destructor" << std::endl;
#endif
}
