#include "ClapTrap.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

ClapTrap::ClapTrap()
	: m_name("Default"), m_hitPoint(10), m_energyPoint(10), m_attackDamage(0)
{
	std::cout << "Default constructor is called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: m_name(name), m_hitPoint(10), m_energyPoint(10), m_attackDamage(0)
{
	std::cout << m_name << " constructor is called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct)
{
	m_name = ct.getName();
	m_hitPoint = ct.getHitPoint();
	m_energyPoint = ct.getEnergyPoint();
	m_attackDamage = ct.getAttackDamage();
	std::cout << m_name << " copy constructor is called." << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& ct)
{
	if (this == &ct)
	{
		std::cout << "The parameter is assigned to itself." << std::endl;
	}
	else
	{
		m_name = ct.getName();
		m_hitPoint = ct.getHitPoint();
		m_energyPoint = ct.getEnergyPoint();
		m_attackDamage = ct.getAttackDamage();
		std::cout << m_name << " is assigned." << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << m_name << " destructor is called." << std::endl;
}

/*******************************************************************************
 * Getter																	   *
 *******************************************************************************/

std::string ClapTrap::getName() const
{
	return m_name;
}
unsigned int ClapTrap::getHitPoint() const
{
	return m_hitPoint;
}
unsigned int ClapTrap::getEnergyPoint() const
{
	return m_energyPoint;
}
unsigned int ClapTrap::getAttackDamage() const
{
	return m_attackDamage;
}

/*******************************************************************************
 * Member Functions															   *
 *******************************************************************************/

void ClapTrap::attack(const std::string& target)
{
	std::cout << m_name;
	if (m_hitPoint == 0 || m_energyPoint == 0)
		std::cout << " is dead....." << std::endl;
	else
	{
		std::cout << " attacks " << target 
			<< ", causing " << m_attackDamage << " points of damage!" << std::endl;
		m_energyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << m_name << " got " << amount << "-damage, and ";
	if (amount >= m_hitPoint)
	{
		m_hitPoint = 0;
		std::cout << "dead." << std::endl;
	}
	else
	{
		m_hitPoint -= amount;
		std::cout << "the rest of hit-point is " << m_hitPoint << "." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << m_name;
	if (m_hitPoint == 0 || m_energyPoint == 0)
		std::cout << " is dead....." << std::endl;
	else
	{
		m_hitPoint += amount;
		std::cout << " got " << amount << " hit-point back! ";
		std::cout << "The rest of hit-point is " << m_hitPoint << "." << std::endl;
		m_energyPoint--;
	}
}
