#include "FragTrap.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

FragTrap::FragTrap()
	: ClapTrap()
{
	m_hitPoint = 100;
	m_energyPoint = 100;
	m_attackDamage = 30;
	std::cout << "FragTrap default constructor is called." << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	m_hitPoint = 100;
	m_energyPoint = 100;
	m_attackDamage = 30;
	std::cout << "FragTrap " << m_name << " constructor is called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& ft)
{
	m_name = ft.getName();
	m_hitPoint = ft.getHitPoint();
	m_energyPoint = ft.getEnergyPoint();
	m_attackDamage = ft.getAttackDamage();
	std::cout << "FragTrap " << m_name << " copy constructor is called." << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& ft)
{
	if (this == &ft)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_name = ft.getName();
		m_hitPoint = ft.getHitPoint();
		m_energyPoint = ft.getEnergyPoint();
		m_attackDamage = ft.getAttackDamage();
		std::cout << "FragTrap " << m_name << " is assigned." << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << m_name << " destructor is called." << std::endl;
}

/*******************************************************************************
 * Member function															   *
 *******************************************************************************/

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << m_name;
	if (m_hitPoint == 0 || m_energyPoint == 0)
		std::cout << " is dead....." << std::endl;
	else
		std::cout << " High Five!" << std::endl;
}
