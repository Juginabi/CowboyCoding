#include "float3.h"

namespace Math
{

// Operator overloads
const float3 operator+(const float3& left, const float3& right)
{
    return float3(left.x + right.x, left.y + right.y, left.z + right.z);
}

const float3 operator+(const float3& left, const int right)
{
    return float3(left.x + right, left.y + right, left.z + right);
}

const float3 operator-(const float3& left, const float3& right)
{
    return float3(left.x - right.x, left.y - right.y, left.z - right.z);
}

const float3 operator-(const float3& left, const int right)
{
    return float3(left.x - right, left.y - right, left.z - right);
}

float3& operator +=(float3& left, const float3& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

}
