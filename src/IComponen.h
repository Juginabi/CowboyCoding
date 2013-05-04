#pragma once


class IComponent
{
public:
    // Destructor
    virtual ~IComponent() { }

    // Update function is overloaded in derived component classes
    virtual void Update() = 0;
};
