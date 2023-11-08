#include "PresidentialPardonForm.hpp"

/*******************************************************************************
 * Orthodox Canonical form													   *
 *******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", SIGN_PARDON, EXEC_PARDON)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf)
	: AForm(ppf)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, SIGN_PARDON, EXEC_PARDON)
{}

// assignment operator overloading unavailable
PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& ppf)
{
	(void)ppf;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

/*******************************************************************************
 * member function															   *
 *******************************************************************************/

void PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	canExecute(b);
	std::cout << getName() << " has been pardon by Zaphod Beeblebrox." << std::endl;
}
