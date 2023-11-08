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

	bool operator > (const Fixed& compare) const;
	bool operator < (const Fixed& compare) const;
	bool operator >= (const Fixed& compare) const;
	bool operator <= (const Fixed& compare) const;
	bool operator == (const Fixed& compare) const;
	bool operator != (const Fixed& compare) const;
	Fixed operator + (const Fixed& operand) const;
	Fixed operator - (const Fixed& operand) const;
	Fixed operator * (const Fixed& operand) const;
	Fixed operator / (const Fixed& operand) const;
	//prefix
	Fixed& operator ++ ();
	Fixed& operator -- ();
	//postfix
	const Fixed operator ++ (int);
	const Fixed operator -- (int);

	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator << (std::ostream& out, const Fixed& f);

#endif
