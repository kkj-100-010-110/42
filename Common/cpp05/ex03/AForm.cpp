#include "AForm.hpp"

/*******************************************************************************
 * Orthodox Canonical form													   *
 *******************************************************************************/

AForm::AForm()
	: m_name("default")
	, m_isSigned(0)
	, m_requiredSign(0)
	, m_requiredExecute(0)
{}

AForm::AForm(const std::string & name, const int sign, const int execute)
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

AForm::AForm(const AForm& f)
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
AForm& AForm::operator = (const AForm& f)
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

AForm::~AForm() {}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

const std::string& AForm::getName() const { return m_name; }

bool AForm::getIsSigned() const { return m_isSigned; }

const int& AForm::getRequiredSign() const { return m_requiredSign; }

const int& AForm::getRequiredExecute() const { return m_requiredExecute; }

void AForm::beSigned(const Bureaucrat& b)
{
	if (m_requiredSign < b.getGrade())
	{
		m_isSigned = false;
		throw GradeTooLowException();
	}
	else
		m_isSigned = true;
}

void AForm::canExecute(const Bureaucrat& b) const
{
	if (m_isSigned == false)
		throw NotSignedException();
	if (m_requiredExecute < b.getGrade())
		throw GradeTooLowException();
}

/*******************************************************************************
 * inner class for exception												   *
 *******************************************************************************/

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "not signed";
}

const char* AForm::FileOpenException::what() const throw()
{
	return "error on opening the file";
}

/*******************************************************************************
 * output stream operator													   *
 *******************************************************************************/

std::ostream& operator << (std::ostream& out, const AForm& f)
{
	out << f.getName() << ", signed : "
		<< std::boolalpha << f.getIsSigned()
		<< ", grade required to sign : "
		<< f.getRequiredSign()	<< ", grade required to execute : "
		<< f.getRequiredExecute() << std::endl;
	return out;
}
