#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

#define SIGN_PARDON 25
#define EXEC_PARDON 5

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm& operator = (const PresidentialPardonForm& ppf);

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& ppf);
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& b) const;
};

#endif
