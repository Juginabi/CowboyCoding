#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers and forward declarations
#include "GOComponent.h"

// Class type definitions

// Class GOC_Position is GameObject-Component storing all position related data.
// GOC_Position is inherited from GOComponent interface base lass.
class GOC_Position : public GOComponent
{
    // GOComponent interface
public:
    const goc_type_id& GetFamilyId() const { return goc_type_id("GOC_Position"); }

    // GOC_Position interface
public:

private:

};
