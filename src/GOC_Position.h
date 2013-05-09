#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers and forward declarations
#include "GOComponent.h"

struct float3 {
    float x;
    float y;
    float z;
};

// Class type definitions

// Class GOC_Position is GameObject-Component storing all position related data.
// GOC_Position is inherited from GOComponent interface base lass.
class GOC_Position : public GOComponent
{
    // GOComponent interface
public:
    // This component is the sole resident of this component family.
    const goc_type_id& GetFamilyId() const { return goc_type_id("GOC_Position"); }
    const goc_type_id& GetComponentId() const { return goc_type_id("GOC_Position"); }

    // GOC_Position interface
public:
    GOC_Position() : position_(float3(0,0,0)) { }

    // Destructor
    ~GOC_Position() { }

    // Returns position float3-struct
    const float3& GetPosition() const;

    // Set position for this GOComponent
    void SetPosition(float _x, float _y, float _z);
    void SetPosition(float3 _position);

private:
    float3 position_;

};

inline const float3& GOC_Position::GetPosition() const
{
    return position_;
}
