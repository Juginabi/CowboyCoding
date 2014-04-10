#pragma once

namespace math
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

    // Syntactic sugar aka. operator overloads.
    friend const float3 operator+(const float3& left, const float3& right);
    friend const float3 operator+(const float3& left, const int right);
    friend const float3 operator-(const float3& left, const float3& right);
    friend const float3 operator-(const float3& left, const int right);
    friend const float3 operator*(const float3& left, const int right);
    friend float3& operator+=(float3& left, const float3& right);

    float x;
    float y;
    float z;
};


} // math namespace
