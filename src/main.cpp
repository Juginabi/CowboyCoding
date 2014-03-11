#include <QCoreApplication>
#include <iostream>
#include "src/scene/gameObject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "CowboyCoding by Jukka V-A!" << std::endl << "Commandline args " << argc << std::endl;

    for (int i = 0; i < argc; ++i)
        std::cout << i << ": " << argv[i] << std::endl;

    gameObject* go = new gameObject("TestObject");
//    go->attachComponent(new GOC_Position());
//    GOC_Position* position = static_cast<GOC_Position*>(go->GetComponent("GOC_Position"));
//    std::cout << "(" << position->GetPosition().x << "," << position->GetPosition().y << "," << position->GetPosition().z << ")" << std::endl;

//    float3 pos = position->GetPosition();
//    // Testing operator overloading
//    pos+=float3(1,2,3);
//    pos+=float3(1,2,3);
//    position->SetPosition(pos);

//    std::cout << "(" << position->GetPosition().x << "," << position->GetPosition().y << "," << position->GetPosition().z << ")" << std::endl;
    delete go;

    return a.exec();
}
