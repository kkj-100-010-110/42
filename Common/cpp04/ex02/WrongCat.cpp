#include "WrongCat.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

WrongCat::WrongCat()
	: WrongAnimal()
{
	m_type = "WrongCat";
	std::cout << m_type << " constructor is called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& wc)
{
	m_type = wc.m_type;
	std::cout << m_type << " copy constructor is called." << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& wc)
{
	if (this == &wc)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_type = wc.m_type;
		std::cout << m_type << " is assigned." << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << m_type << " destructor is called." << std::endl;
}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

void WrongCat::makeSound() const { std::cout << "Meow~" << std::endl; }
