#include "ShrubberyCreationForm.hpp"

/*******************************************************************************
 * Orthodox Canonical form													   *
 *******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", SIGN_SHRUBBERY, EXEC_SHRUBBERY)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf)
	: AForm(scf)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, SIGN_SHRUBBERY, EXEC_SHRUBBERY)
{}

// assignment operator overloading unavailable
ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& scf)
{
	(void)scf;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

/*******************************************************************************
 * member function															   *
 *******************************************************************************/

void ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	canExecute(b);
	std::ofstream of(getName() + "_shrubbery");
	if (!of.good())
		throw FileOpenException();
	std::string trees =
		"              ,@@@@@@@,\n"
		"      ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		"  ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		"  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		"  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		"  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		"  `&%\\ ` /%&'    |.|        \\ '|8'\n"
		"      |o|        | |         | |\n"
		"      |.|        | |         | |\n"
		"   \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
	of << trees;
	of.close();
	std::cout << "[Created the file]" << std::endl;
}
