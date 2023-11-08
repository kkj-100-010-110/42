#include "Convert.hpp"

/*******************************************************************************
 *  Orthodox Canonical Form													   *
 *******************************************************************************/

Convert::Convert()
	: m_error(false), m_input(""), m_value(0.0)
{}

Convert::Convert(const std::string& input)
	: m_error(false), m_input(input), m_value(0.0)
{
	try
	{
		char* pos = NULL;
		const_cast<double&>(m_value) = std::strtod(m_input.c_str(), &pos);
		if (m_value == 0.0 && (m_input[0] != '-' && m_input[0] != '+' && !std::isdigit(m_input[0])))
			throw InputValidException();
		if (*pos && std::strcmp(pos, "f"))
			throw InputValidException();
	}
	catch (std::exception& e)
	{
		m_error = true;
		std::cout << e.what() << std::endl;;
	}
}

Convert::Convert(const Convert& c)
	: m_error(false), m_input(c.getInput()), m_value(c.getValue())
{}

Convert& Convert::operator = (const Convert& c)
{
	if (this == &c)
		return *this;
	m_error = c.m_error;
	const_cast<std::string&>(m_input) = c.m_input;
	const_cast<double&>(m_value) = c.m_value;
	return *this;
}

Convert::~Convert()
{}

/*******************************************************************************
 *  member functions														   *
 *******************************************************************************/

char Convert::toChar() const
{
	return static_cast<char>(m_value);
}

int Convert::toInt() const
{
	return static_cast<int>(m_value);
}

float Convert::toFloat() const
{
	return static_cast<float>(m_value);
}

double Convert::toDouble() const
{
	return static_cast<double>(m_value);
}

bool Convert::getError() const
{
	return m_error;
}

const double& Convert::getValue() const
{
	return m_value;
}

const std::string& Convert::getInput() const
{
	return m_input;
}

void Convert::print() const
{
	printChar();
	printInt();
	printFloat();
}

void Convert::printChar() const
{
	std::cout << "char: ";
	if (std::isnan(m_value) || std::isinf(m_value))
		std::cout << IM << std::endl;
	else
	{
		if (m_value > std::numeric_limits<char>::max())
			std::cout << "overflow value ";
		else if (m_value < std::numeric_limits<char>::min())
			std::cout << "underflow value ";
		if (std::isprint(toChar()))
			std::cout << "'" << toChar() << "'" << std::endl;
		else
			std::cout << ND << std::endl;
	}
}

void Convert::printInt() const
{
	std::cout << "int: ";
	if (std::isnan(m_value) || std::isinf(m_value))
		std::cout << IM << std::endl;
	else
	{
		if (m_value > std::numeric_limits<int>::max())
			std::cout << "overflow value ";
		else if (m_value < std::numeric_limits<int>::min())
			std::cout << "underflow value ";
		std::cout << toInt() << std::endl;
	}

}

void Convert::printFloat() const
{
	if (std::isnan(m_value) || std::isinf(m_value))
	{
		std::cout << "float: " << std::showpos << toFloat() << "f" << std::endl;
		std::cout << "double: " << std::showpos << toDouble() << std::endl;
		return;
	}
	std::cout << "float: ";
	if (toFloat() == static_cast<int64_t>(toFloat()))
		std::cout << toFloat() << ".0f" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << toFloat() << "f" << std::endl;
	std::cout << "double: ";
	if (toDouble() == static_cast<int64_t>(toDouble()))
		std::cout << toDouble() << ".0" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << toDouble() << std::endl;
}

/*******************************************************************************
 *  exception																   *
 *******************************************************************************/

const char* Convert::InputValidException::what() const throw()
{
	return "Your input value is invalid.";
}

/*******************************************************************************
 *  output stream operator													   *
 *******************************************************************************/

std::ostream& operator << (std::ostream& out, const Convert& c)
{
	if (c.getError())
	{
		out << " Cannot convert " << c.getInput() << std::endl;
		return out;
	}
	c.print();
	return out;
}
