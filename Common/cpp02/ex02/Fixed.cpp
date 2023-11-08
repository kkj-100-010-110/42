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
	m_value = 0;
}

Fixed::Fixed(const Fixed& source)
{
	m_value = source.getRawBits();
}

Fixed::Fixed(const int ivalue)
{
	m_value = ivalue << m_frac_bits;
}

Fixed::Fixed(const float fvalue)
{
	m_value = roundf(fvalue * (1 << m_frac_bits));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator = (const Fixed& source)
{
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

/*******************************************************************************
 * 6 comparison																   *
 * 4 arithmetic																   *
 * 4 increment/decrement													   *
 *******************************************************************************/

bool Fixed::operator > (const Fixed& compare) const
{
	return m_value > compare.getRawBits();
}

bool Fixed::operator < (const Fixed& compare) const
{
	return m_value < compare.getRawBits();
}

bool Fixed::operator >= (const Fixed& compare) const
{
	return m_value >= compare.getRawBits();
}

bool Fixed::operator <= (const Fixed& compare) const
{
	return m_value <= compare.getRawBits();
}

bool Fixed::operator == (const Fixed& compare) const
{
	return m_value == compare.getRawBits();
}

bool Fixed::operator != (const Fixed& compare) const
{
	return m_value != compare.getRawBits();
}

Fixed Fixed::operator + (const Fixed& operand) const
{
	return Fixed(this->toFloat() + operand.toFloat());
}

Fixed Fixed::operator - (const Fixed& operand) const
{
	return Fixed(this->toFloat() - operand.toFloat());
}

Fixed Fixed::operator * (const Fixed& operand) const
{
	return Fixed(this->toFloat() * operand.toFloat());
}

Fixed Fixed::operator / (const Fixed& operand) const
{
	return Fixed(this->toFloat() / operand.toFloat());
}

//prefix
Fixed& Fixed::operator ++ ()
{
	++m_value;
	return *this;
}

Fixed& Fixed::operator -- ()
{
	--m_value;
	return *this;
}

//postfix
const Fixed Fixed::operator ++ (int)
{
	Fixed temp(*this);

	++m_value;

	return temp;
}

const Fixed Fixed::operator -- (int)
{
	Fixed temp(*this);

	--m_value;

	return temp;
}

/*******************************************************************************
 * 4 overloaded member function												   *
 *******************************************************************************/

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	return f1 <= f2 ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return f1 <= f2 ? f1 : f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	return f1 >= f2 ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return f1 >= f2 ? f1 : f2;
}
