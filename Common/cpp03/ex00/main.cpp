#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Clap");
	ClapTrap b("Trap");
	ClapTrap c;
	ClapTrap d;
	ClapTrap e;

	c = a;
	d = b;

	a.attack("A");
	a.attack("B");
	a.attack("C");

	a.takeDamage(5);
	a.takeDamage(5);
	b.takeDamage(3);
	b.takeDamage(3);
	b.takeDamage(3);
	b.takeDamage(3);
	a.beRepaired(5);
	b.beRepaired(5);
	c.beRepaired(5);
	d.beRepaired(5);

	return 0;
}
