#include "Dog.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

Dog::Dog()
	: Animal()
{
	m_type = "Dog";
	std::cout << m_type << " constructor is called." << std::endl;
}

Dog::Dog(const Dog& d)
{
	m_type = d.m_type;
	std::cout << m_type << " copy constructor is called." << std::endl;
}

Dog& Dog::operator = (const Dog& d)
{
	if (this == &d)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_type = d.m_type;
		std::cout << m_type << " is assigned." << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << m_type << " destructor is called." << std::endl;
}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
