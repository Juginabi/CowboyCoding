#pragma once

#ifndef _NDEBUG
    #include <iostream>
#endif

// Project specific headers and forward declarations
#include "gocVisual.h"

class GocVisualRectangle : public GocVisual {
    // GocVisual interface
public:
    // Constructor
    GocVisualRectangle();

    // Destructor
    virtual ~GocVisualRectangle();

    // Can be used to query component id
    const goc_type_id &getComponentId() const;

    // This method renders the entity visual on screen.
    virtual void render() const;

private:
    static const goc_type_id componentId_;
};

inline const goc_type_id &GocVisualRectangle::getComponentId() const {
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
