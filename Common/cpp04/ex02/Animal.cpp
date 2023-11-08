#include "Animal.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

Animal::Animal()
	: m_type("Non-type")
{
	std::cout << m_type << " default constructor is called." << std::endl;

}

Animal::Animal(const Animal& a)
	: m_type(a.m_type)
{
	std::cout << m_type << " copy constructor is called." << std::endl;
}

Animal& Animal::operator = (const Animal& a)
{
	if (this == &a)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_type = a.m_type;
		std::cout << m_type << " is assigned." << std::endl;
	}
	return *this;

}

Animal::~Animal()
{
	std::cout << m_type << " destructor is called." << std::endl;
}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

std::string Animal::getType() const { return m_type; }
