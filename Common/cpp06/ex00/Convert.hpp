#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>	//.c_str()
#include <iomanip>	// setprecision
#include <cmath>	//isnan & isinf
#include <cstdlib>	//strtod
#include <cstdint>	//int64_t
#include <exception>
#include <limits>	//numeric_limits

#define ND "Non displayable"
#define IM "impossible"

class Convert
{
private:
	bool m_error;
	const std::string m_input;
	const double m_value;

private:
	Convert();

public:
	Convert(const std::string& m_input);
	Convert(const Convert& c);
	Convert& operator = (const Convert& c);
	~Convert();

	char toChar() const;
	int toInt() const;
	float toFloat() const;
	double toDouble() const;

	bool getError() const;
	const double& getValue() const;
	const std::string& getInput() const;

	void print() const;
	void printChar() const;
	void printInt() const;
	void printFloat() const;

	class InputValidException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator << (std::ostream& out, const Convert& c);

#endif
