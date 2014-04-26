#pragma once

// Project specific headers and forward declarations
#include "gocVisual.h"

#ifndef _NDEBUG
    #include <iostream>
#endif

class GocVisualRectangle : public GocVisual
{
    // Class type definitions
    typedef std::string goc_type_id;

    // GocVisual interface
public:
    // Destructor
    ~GocVisualRectangle();

    // Can be used to query family id of components inherited from this.
    const goc_type_id getComponentId() const;

    // This method renders the entity visual on screen.
    void render() const;
};

inline const goc_type_id GocVisualRectangle::getComponentId() const {
    return goc_type_id("GocVisualRectangle");
}

inline GocVisualRectangle::~GocVisualRectangle() {
#ifndef _NDEBUG
    std::cout << "GocVisualRectangle destructor" << std::endl;
#endif
}
