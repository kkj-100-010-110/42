#include "Fixed.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 * -Default constructor														   *
 * -Copy constructor														   *
 * -Copy assignment operator												   *
 * -Destructor																   *
 *******************************************************************************/

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

Fixed::Fixed(const int ivalue)
{
	std::cout << "Int constructor called" << std::endl;
	m_value = ivalue << m_frac_bits;
}

Fixed::Fixed(const float fvalue)
{
	std::cout << "Float constructor called" << std::endl;
	m_value = roundf(fvalue * (1 << m_frac_bits));
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

/*******************************************************************************
 * Fixed-point 																   *
 * setter & getter															   *
 *******************************************************************************/

float Fixed::toFloat(void) const
{
	return static_cast<float>(m_value) / (1 << m_frac_bits);
}

int Fixed::toInt(void) const
{
	return m_value >> m_frac_bits;
}

int Fixed::getRawBits(void) const
{
	return m_value;
}

void Fixed::setRawBits(int const raw)
{
	m_value = raw;
}

/*******************************************************************************
 * output stream operator													   *
 *******************************************************************************/

std::ostream& operator << (std::ostream& out, const Fixed& f)
{
	out << f.toFloat();
	return out;
}
