#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int m_value;
	static const int m_frac_bits = 8;

public:
	Fixed();
	Fixed(const Fixed& source);
	Fixed(const int ivalue);
	Fixed(const float fvalue);
	~Fixed();
	Fixed& operator = (const Fixed& source);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator << (std::ostream& out, const Fixed& f);

#endif
