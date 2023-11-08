#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string m_name;
	Weapon& m_weapon;

public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();

	void attack(void) const;
};

#endif
