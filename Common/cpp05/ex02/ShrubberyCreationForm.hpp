#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

#define SIGN_SHRUBBERY 145
#define EXEC_SHRUBBERY 137

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& scf);

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& scf);
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	
	void execute(const Bureaucrat& b) const;
};

#endif
