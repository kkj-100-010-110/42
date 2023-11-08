#include "Bureaucrat.hpp"

/*******************************************************************************
 * Orthodox Canonical form													   *
 *******************************************************************************/

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
	: m_name(name), m_grade(grade)
{
	if (m_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (m_grade > MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
	: m_name(b.getName()), m_grade(b.getGrade())
{
	if (m_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (m_grade > MIN_GRADE)
		throw GradeTooLowException();
}

// assignment operator overloading unavailable
Bureaucrat& Bureaucrat::operator = (const Bureaucrat& b)
{
	if (this == &b)
		return *this;
	const_cast<std::string&>(m_name) = b.getName();
	m_grade = b.m_grade;
	if (m_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (m_grade > MIN_GRADE)
		throw GradeTooLowException();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

void Bureaucrat::increment()
{
	if (m_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	m_grade--;
}

void Bureaucrat::decrement()
{
	if (m_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	m_grade++;
}

void Bureaucrat::signForm(const AForm& f) const
{
	try
	{
		const_cast<AForm&>(f).beSigned(*this);
		std::cout << m_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << m_name << " couldn't sign " << f.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &f) const
{
	try
	{
		const_cast<AForm &>(f).beSigned(*this);
		std::cout << m_name << " executed " << f.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << m_name << " couldn't execute " << f.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

const std::string& Bureaucrat::getName() const { return m_name; }

int Bureaucrat::getGrade() const { return m_grade; }

/*******************************************************************************
 * inner class for exception												   *
 *******************************************************************************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

/*******************************************************************************
 * output stream operator													   *
 *******************************************************************************/

std::ostream& operator << (std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}
