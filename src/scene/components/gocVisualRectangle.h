#pragma once

// Project specific headers and forward declarations
#include "gocVisual.h"

#ifndef _NDEBUG
    #include <iostream>
#endif

class GocVisualRectangle : public GocVisual
{
    // GocVisual interface
public:
    // Constructor
    GocVisualRectangle();

    // Destructor
    ~GocVisualRectangle();

    // Can be used to query family id of components inherited from this.
    const goc_type_id& getComponentId() const;

    // This method renders the entity visual on screen.
    void render() const;

private:
    static const goc_type_id componentId_;
};

inline const goc_type_id& GocVisualRectangle::getComponentId() const {
    return componentId_;
}

inline GocVisualRectangle::~GocVisualRectangle() {
#ifndef _NDEBUG
    std::cout << "[GocVisualRectangle] destructor" << std::endl;
#endif
}

inline GocVisualRectangle::GocVisualRectangle() {
#ifndef _NDEBUG
    std::cout << "[GocVisualRectangle] constructor" << std::endl;
#endif
}
