#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Scav");
	ScavTrap b("Trap");
	ScavTrap c(a);
	ScavTrap d;

	d = b;

	a.attack("A");
	a.attack("B");
	a.attack("C");
	b.attack("A");
	b.attack("B");
	b.attack("C");

	a.guardGate();
	b.guardGate();

	return 0;
}
