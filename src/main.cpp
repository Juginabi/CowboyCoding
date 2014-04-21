#include <QCoreApplication>
#include <iostream>
#include "src/scene/gameObject.h"
#include "src/scene/components/gocVisualSphere.h"
#include "src/scene/components/gocVisualRectangle.h"
#include "math/float3.h"

using namespace math;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "CowboyCoding by Jukka V-A!" << std::endl << "Commandline args " << argc << std::endl;

    for (int i = 0; i < argc; ++i)
        std::cout << i << ": " << argv[i] << std::endl;

    GameObject go("stackAllocated");

    // Attach visual Component
    go.attachComponent(new gocVisualSphere());

    // Attach another visual Component. Return value is replaced Component.
    Component* co2 = go.attachComponent(new gocVisualRectangle());

    // Delete replaced Component
    if (co2)
        delete co2;

    Float3 newFloat1(1,2,3), newFloat2(3,4,5);
    Float3 result = newFloat1+newFloat2;

    return a.exec();
}
