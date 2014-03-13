#pragma once

// Project specific headers and forward declarations
#include "gocVisual.h"

class gocVisualRectangle : public gocVisual
{
    // Class type definitions
    typedef std::string goc_type_id;

    // gocVisual interface
public:
    const goc_type_id getComponentId() const { return goc_type_id("gocVisualRectangle"); }

    // This method renders the entity visual on screen.
    virtual void render() const;
};
