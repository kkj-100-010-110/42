#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie zombie_main("main");
	Zombie *zombie_heap(newZombie("heap"));

	randomChump("function");
	zombie_main.announce();
	zombie_heap->announce();
//(*zombie_heap).announce();

	delete zombie_heap;

	return 0;
}
