#include "FragTrap.hpp"

int main()
{
	FragTrap a("Frag");
	FragTrap b("Trap");
	FragTrap c(a);
	FragTrap d;

	d = b;

	a.attack("A");
	a.attack("B");

	a.highFiveGuys();

	return 0;
}
