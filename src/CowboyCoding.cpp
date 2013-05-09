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

	delete go;


	return 0;
}
