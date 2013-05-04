#pragma once

#include "IComponen.h"

class ExampleComponent : public IComponent
{
public:
    // Constructor
    ExampleComponent();

    // Destructor
    ~ExampleComponent();

    // This updates the component
    void Update();
private:
    long lastUpdate_;
};
