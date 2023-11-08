#include "Form.hpp"

/*******************************************************************************
 * Orthodox Canonical form													   *
 *******************************************************************************/

Form::Form()
	: m_name("unnamed")
	, m_isSigned(0)
	, m_requiredSign(0)
	, m_requiredExecute(0)
{}

Form::Form(const std::string & name, const int sign, const int execute)
	: m_name(name)
	, m_isSigned(0)
	, m_requiredSign(sign)
	, m_requiredExecute(execute)
{
	if (m_requiredSign < MAX_GRADE || m_requiredExecute < MAX_GRADE)
		throw GradeTooHighException();
	if (m_requiredSign > MIN_GRADE || m_requiredExecute > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form& f)
	: m_name(f.m_name)
	, m_isSigned(f.m_isSigned)
	, m_requiredSign(f.m_requiredSign)
	, m_requiredExecute(f.m_requiredExecute)
{
	if (m_requiredSign < MAX_GRADE || m_requiredExecute < MAX_GRADE)
		throw GradeTooHighException();
	if (m_requiredSign > MIN_GRADE || m_requiredExecute > MIN_GRADE)
		throw GradeTooLowException();
}

// assignment operator overloading unavailable
Form& Form::operator = (const Form& f)
{
	if (this == &f)
		return *this;
	const_cast<std::string&>(m_name) = f.m_name;
	const_cast<int&>(m_requiredSign) = f.m_requiredSign;
	const_cast<int&>(m_requiredExecute) = f.m_requiredExecute;
	m_isSigned = f.m_isSigned;
	if (m_requiredSign < MAX_GRADE || m_requiredExecute < MAX_GRADE)
		throw GradeTooHighException();
	if (m_requiredSign > MIN_GRADE || m_requiredExecute > MIN_GRADE)
		throw GradeTooLowException();
	return *this;
}

Form::~Form() {}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

const std::string& Form::getName() const { return m_name; }

bool Form::getIsSigned() const { return m_isSigned; }

const int& Form::getRequiredSign() const { return m_requiredSign; }

const int& Form::getRequiredExecute() const { return m_requiredExecute; }

void Form::beSigned(const Bureaucrat& b)
{
	if (m_requiredSign < b.getGrade())
	{
		m_isSigned = false;
		throw GradeTooLowException();
	}
	else
		m_isSigned = true;
}

/*******************************************************************************
 * inner class for exception												   *
 *******************************************************************************/

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

/*******************************************************************************
 * output stream operator													   *
 *******************************************************************************/

std::ostream& operator << (std::ostream& out, const Form& f)
{
	out << f.getName() << ", signed : "
		<< std::boolalpha << f.getIsSigned()
		<< ", grade required to sign : "
		<< f.getRequiredSign()	<< ", grade required to execute : "
		<< f.getRequiredExecute() << std::endl;
	return out;
}
