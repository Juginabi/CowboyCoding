#pragma once

namespace Math
{

class float3
{
public:
    // Defaut constructor
    float3() : x(0.0f), y(0.0f), z(0.0f) { }

    // Custom constructors
    float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }

    // Destructor
    ~float3() { }

    float x;
    float y;
    float z;
};

} // Math namespace
