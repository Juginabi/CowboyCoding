#include <memory>
#ifndef _NDEBUG
    #include <iostream>
#endif
#include "src/scene/gameObject.h"
#include "src/scene/components/gocVisualRectangle.h"
#include "src/scene/components/gocVisualSphere.h"
#include "src/scene/gameObjectManager.h"
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
        GameObject *go = new GameObject("Somename");
        Component *goc = new GocVisualRectangle;
        Component *goc2 = new GocVisualSphere;
        gameObjectManager *goManager = gameObjectManager::getInstance();

        // Test attach with ownership transfer then clear all components
        go->attachComponent(goc);
        go->attachComponent(goc2);
        go->clearComponents();
    } catch (std::bad_alloc &e) {
        return EXIT_FAILURE;
    }

   return EXIT_SUCCESS;
}
