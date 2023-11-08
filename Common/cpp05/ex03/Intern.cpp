#include "Intern.hpp"

/*******************************************************************************
 * Orthodox Canonical form													   *
 *******************************************************************************/

Intern::Intern()
{}

Intern::Intern(const Intern& i) { *this = i; }

Intern& Intern::operator = (const Intern& i)
{
	(void)i;
	return *this;
}

Intern::~Intern()
{}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

AForm* Intern::create_shrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::create_robotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::create_pardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	const std::string forms[3] = { "Shrubbery"
								  ,"Robotomy"
								  ,"Pardon" };

	AForm *(Intern::*f_ptr[3])(const std::string&) = {&Intern::create_shrubbery
													, &Intern::create_robotomy
													, &Intern::create_pardon};
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
			return (this->*f_ptr[i])(target);
	}
	throw NoFormException();
}

/*******************************************************************************
 * inner class for exception												   *
 *******************************************************************************/

const char* Intern::NoFormException::what() const throw()
{
	return "no matching form";
}
