#include <memory>
#include <iostream>
#include "src/scene/gameObject.h"
#include "src/scene/components/gocVisualSphere.h"
#include "src/scene/components/gocVisualRectangle.h"
#include "math/float3.h"
#include "commonTypeDefs.h"

using namespace Math;

int main(int argc, char *argv[])
{
    std::cout << "CowboyCoding by Jukka V-A!" << std::endl << "Commandline args " << argc << std::endl;

    for (int i = 0; i < argc; ++i)
        std::cout << i << ": " << argv[i] << std::endl;

    GameObjectPtr go(new GameObject("Somename"));
    ComponentPtr goc(new GocVisualRectangle);
    ComponentPtr goc2(new GocVisualSphere);

    // Test attach with ownership transfer then clear all components
    go->attachComponent(std::move(goc));
    go->attachComponent(std::move(goc2));
    go->clearComponents();

   return 0;
}
