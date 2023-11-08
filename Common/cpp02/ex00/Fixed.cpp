#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	m_value = 0;
}

Fixed::Fixed(const Fixed& source)
{
	std::cout << "Copy constructor called" << std::endl;
	m_value = source.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& source)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &source)
		m_value = source.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return m_value;
}

void Fixed::setRawBits(int const raw)
{
	m_value = raw;
}
