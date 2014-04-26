#pragma once

namespace Math
{

class Float3
{
public:
    // Defaut constructor
    Float3() : x(0.0f), y(0.0f), z(0.0f) { }

    // Custom constructors
    Float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }

    // Destructor
    ~Float3() { }

    // Normalizes this Float3
    void normalize();

    // Returns unit vector from this Float3
    Float3 getNormalized() const;

    // Return length of this vector
    double getLengthSquared() const;

    // Return non-squared length of this vector
    double getLengthNonSquared() const;

    // Syntactic sugar aka. operator overloads.
    friend const Float3 operator+(const Float3& left, const Float3& right);
    friend const Float3 operator+(const Float3& left, const int right);
    friend const Float3 operator-(const Float3& left, const Float3& right);
    friend const Float3 operator-(const Float3& left, const int right);
    friend const Float3 operator*(const Float3& left, const int right);
    friend Float3& operator+=(Float3& left, const Float3& right);

    float x;
    float y;
    float z;
};


} // math namespace
