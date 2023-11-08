#include "ScavTrap.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

ScavTrap::ScavTrap()
	: ClapTrap()
{
	m_hitPoint = 100;
	m_energyPoint = 50;
	m_attackDamage = 20;
	std::cout << "ScavTrap default constructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	m_hitPoint = 100;
	m_energyPoint = 50;
	m_attackDamage = 20;
	std::cout << "ScavTrap " << m_name << " constructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& st)
{
	m_name = st.getName();
	m_hitPoint = st.getHitPoint();
	m_energyPoint = st.getEnergyPoint();
	m_attackDamage = st.getAttackDamage();
	std::cout << "ClapTrap " << m_name << " copy constructor is called." << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& st)
{
	if (this == &st)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_name = st.getName();
		m_hitPoint = st.getHitPoint();
		m_energyPoint = st.getEnergyPoint();
		m_attackDamage = st.getAttackDamage();
		std::cout << "ScavTrap " << m_name << " is assigned." << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << m_name << " destructor is called." << std::endl;
}

/*******************************************************************************
 * Member Functions															   *
 *******************************************************************************/

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << m_name;
	if (m_hitPoint == 0 || m_energyPoint == 0)
		std::cout << " is dead....." << std::endl;
	else
		std::cout << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << m_name;
	if (m_hitPoint == 0 || m_energyPoint == 0)
		std::cout << " is dead....." << std::endl;
	else
	{
		std::cout << " attacks " << target 
			<< ", causing " << m_attackDamage << " points of damage!" << std::endl;
		m_energyPoint--;
	}
}
