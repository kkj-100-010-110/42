#include "Convert.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "You put the wrong number of arguments." << std::endl;
		std::cout << "Try this way -> './convert argument'" << std::endl;
		return 1;
	}
	Convert c(argv[1]);
	if (c.getError())
		return 1;
	c.print();
	
	return 0;
}
