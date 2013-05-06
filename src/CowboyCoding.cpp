#include <iostream>
#include "GameObject.h"

int main(int argc, char *argv[])
{
	std::cout << "CowboyCoding by Jukka V-A!" << std::endl << "Commandline args " << argc << std::endl;

	for (int i = 0; i < argc; ++i)
		std::cout << i << ": " << argv[i] << std::endl; 


	return 0;
}
