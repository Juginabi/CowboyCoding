#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers and forward declarations
#include "gocVisual.h"

class gocVisualSphere : public gocVisual
{
    // Class type definitions
    typedef std::string goc_type_id;

    // gocVisual interface
public:
    const goc_type_id getComponentId() const { return goc_type_id("gocVisualSphere"); }

    // This method renders the entity visual on screen.
    virtual void render() const;
};
