#include "float3.h"

namespace Math
{

// Operator overloads
const Float3 operator+(const Float3& left, const Float3& right)
{
    return Float3(left.x + right.x, left.y + right.y, left.z + right.z);
}

const Float3 operator+(const Float3& left, const int right)
{
    return Float3(left.x + right, left.y + right, left.z + right);
}

const Float3 operator-(const Float3& left, const Float3& right)
{
    return Float3(left.x - right.x, left.y - right.y, left.z - right.z);
}

const Float3 operator-(const Float3& left, const int right)
{
    return Float3(left.x - right, left.y - right, left.z - right);
}

const Float3 operator*(const Float3& left, const int right)
{
    return Float3(left.x * right, left.y * right, left.z * right);
}

Float3& operator +=(Float3& left, const Float3& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

}
