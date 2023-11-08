#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string m_name;
	unsigned int m_hitPoint;
	unsigned int m_energyPoint;
	unsigned int m_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& ct);
	ClapTrap& operator = (const ClapTrap& ct);
	~ClapTrap();

	std::string getName() const;
	unsigned int getHitPoint() const;
	unsigned int getEnergyPoint() const;
	unsigned int getAttackDamage() const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
