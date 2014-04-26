#include "float3.h"
#include <math.h>

namespace Math
{

void Float3::normalize() {
    double length = getLengthSquared();
    x = x/length;
    y = y/length;
    z = z/length;
}

double Float3::getLengthSquared() const {
    return sqrt(pow(x, 2) + pow(y,2) + pow(z,2));
}

double Float3::getLengthNonSquared() const {
    return pow(x, 2) + pow(y,2) + pow(z,2);
}

// Operator overloads
const Float3 operator+(const Float3& left, const Float3& right) {
    return Float3(left.x + right.x, left.y + right.y, left.z + right.z);
}

const Float3 operator+(const Float3& left, const int right) {
    return Float3(left.x + right, left.y + right, left.z + right);
}

const Float3 operator-(const Float3& left, const Float3& right) {
    return Float3(left.x - right.x, left.y - right.y, left.z - right.z);
}

const Float3 operator-(const Float3& left, const int right) {
    return Float3(left.x - right, left.y - right, left.z - right);
}

const Float3 operator*(const Float3& left, const int right) {
    return Float3(left.x * right, left.y * right, left.z * right);
}

Float3& operator +=(Float3& left, const Float3& right) {
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

}
