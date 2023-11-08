#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	m_name = name;
	std::cout << "Zombie, " << m_name << ", created." << std::endl;
}

Zombie::Zombie()
{
	m_name = "no-name";
	std::cout << "Zombie, " << m_name << ", created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie, " << m_name << ", destroyed." << std::endl;
}

void Zombie::setName(std::string name)
{
	m_name = name;
}

void Zombie::announce()
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
