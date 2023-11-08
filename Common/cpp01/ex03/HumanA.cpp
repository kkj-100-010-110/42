#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: m_name(name), m_weapon(weapon)
{}

HumanA::~HumanA()
{}

void HumanA::attack(void) const
{
	std::cout << m_name << " attack with his " << m_weapon.getType() << std::endl;
}
