#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
	: m_name(name)
{}

HumanB::~HumanB()
{}

void HumanB::setWeapon(Weapon& weapon)
{
	m_weapon = &weapon;
}

void HumanB::attack(void) const
{
	std::cout << m_name << " attack with his " << m_weapon->getType() << std::endl;
}
