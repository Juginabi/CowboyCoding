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
    // Constructor
    GocVisualSphere();

    // Destructor
    ~GocVisualSphere();

    // Can be used to query family id of components inherited from this.
    const goc_type_id &getComponentId() const;

    // This method renders the entity visual on screen.
    void render() const;

private:
    static const goc_type_id componentId_;
};

inline const goc_type_id &GocVisualSphere::getComponentId() const {
    return componentId_;
}

inline GocVisualSphere::~GocVisualSphere() {
#ifndef _NDEBUG
    std::cout << "[GocVisualSphere] destructor" << std::endl;
#endif
}

inline GocVisualSphere::GocVisualSphere() {
#ifndef _NDEBUG
    std::cout << "[GocVisualSphere] constructor" << std::endl;
#endif
}
