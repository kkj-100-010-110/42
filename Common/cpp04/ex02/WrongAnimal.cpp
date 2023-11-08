#include "WrongAnimal.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

WrongAnimal::WrongAnimal()
	: m_type("Non-type")
{
	std::cout << m_type << " default constructor is called." << std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal& wa)
	: m_type(wa.getType())
{
	std::cout << m_type << " copy constructor is called." << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& wa)
{
	if (this == &wa)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_type = wa.m_type;
		std::cout << m_type << " is assigned." << std::endl;
	}
	return *this;

}

WrongAnimal::~WrongAnimal()
{
	std::cout << m_type << " destructor is called." << std::endl;
}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

std::string WrongAnimal::getType() const { return m_type; }
void WrongAnimal::makeSound() const { std::cout << "....." << std::endl; }
