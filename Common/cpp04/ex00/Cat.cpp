#include "Cat.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

Cat::Cat()
	: Animal()
{
	m_type = "Cat";
	std::cout << m_type << " constructor is called." << std::endl;
}

Cat::Cat(const Cat& c)
{
	m_type = c.m_type;
	std::cout << m_type << " copy constructor is called." << std::endl;
}

Cat& Cat::operator = (const Cat& c)
{
	if (this == &c)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_type = c.m_type;
		std::cout << m_type << " is assigned." << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << m_type << " destructor is called." << std::endl;
}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

void Cat::makeSound() const { std::cout << "Meow~" << std::endl; }
