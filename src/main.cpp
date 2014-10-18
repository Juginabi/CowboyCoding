#include <memory>
#ifndef _NDEBUG
    #include <iostream>
#endif
#include "src/scene/gameObject.h"
#include "src/scene/components/gocVisualRectangle.h"
#include "src/scene/components/gocVisualSphere.h"
#include "math/float3.h"
#include "commonTypeDefs.h"

using namespace Math;

int main(int argc, char *argv[])
{
#ifndef _NDEBUG
    std::cout << "CowboyCoding by Jukka V-A!" << std::endl << "Commandline args " << argc << std::endl;
#endif


    for (int i = 0; i < argc; ++i)
        std::cout << i << ": " << argv[i] << std::endl;

    try {
        GameObjectPtr go(new GameObject("Somename"));
        ComponentPtr goc(new GocVisualRectangle);
        ComponentPtr goc2(new GocVisualSphere);

        // Test attach with ownership transfer then clear all components
        go->attachComponent(std::move(goc));
        go->attachComponent(std::move(goc2));
        go->clearComponents();
    } catch (std::bad_alloc &e) {
        return EXIT_FAILURE;
    }

   return EXIT_SUCCESS;
}
