#include "GOC_Position.h"

void GOC_Position::SetPosition(float _x, float _y, float _z)
{
    position_.x = _x;
    position_.y = _y;
    position_.z = _z;
}

void GOC_Position::SetPosition(float3 _position)
{
    position_ = _position;
}
