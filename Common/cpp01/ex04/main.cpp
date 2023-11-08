#include <iostream>
#include "Replace.hpp"

int main(int argc, char** argv)
{
	Replace r;

	if (argc == 4)
	{
		r.getData(argv[1], argv[2], argv[3]);
		r.replace();
	}
	else
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return 1;
	}

	return 0;
}
