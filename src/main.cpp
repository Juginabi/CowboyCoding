#include <QCoreApplication>
#include <iostream>
#include "src/scene/gameObject.h"
#include "src/scene/components/gocVisualSphere.h"
#include "src/scene/components/gocVisualRectangle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "CowboyCoding by Jukka V-A!" << std::endl << "Commandline args " << argc << std::endl;

    for (int i = 0; i < argc; ++i)
        std::cout << i << ": " << argv[i] << std::endl;

    gameObject* go = new gameObject("TestObject");
    component* co1 = go->attachComponent(new gocVisualSphere());
    if (!co1)
        std::cout << "component null!\n";
    component* co2 = go->attachComponent(new gocVisualRectangle());
    std::cout << "component is: " << co2->getComponentId() << std::endl;
    component* co3 = go->getComponent("gocVisual");
    std::cout << "component is: " << co3->getComponentId() << std::endl;

    delete go;

    return a.exec();
}
