#include <iostream>
#include "GameObject.h"
#include "GOComponent.h"
#include "GOC_Position.h"

int main(int argc, char *argv[])
{
	std::cout << "CowboyCoding by Jukka V-A!" << std::endl << "Commandline args " << argc << std::endl;

	for (int i = 0; i < argc; ++i)
		std::cout << i << ": " << argv[i] << std::endl;

	GameObject* go = new GameObject("TestObject");
    go->AttachComponent(new GOC_Position());
    GOC_Position* position = static_cast<GOC_Position*>(go->GetComponent("GOC_Position"));
    std::cout << "(" << position->GetPosition().x << "," << position->GetPosition().y << "," << position->GetPosition().z << ")" << std::endl;

    position->SetPosition(float3(1.2f, 2.0f, -4.6f));

    std::cout << "(" << position->GetPosition().x << "," << position->GetPosition().y << "," << position->GetPosition().z << ")" << std::endl;
	delete go;


	return 0;
}
