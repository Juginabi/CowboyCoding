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

    gameObject go("stackAllocated");

    // Attach visual component
    go.attachComponent(new gocVisualSphere());

    // Attach another visual component. Return value is replaced component.
    component* co2 = go.attachComponent(new gocVisualRectangle());

    // Delete replaced component
    if (co2)
        delete co2;

    float3 newFloat1(1,2,3), newFloat2(3,4,5);
    float3 result = newFloat1+newFloat2;

    return a.exec();
}
