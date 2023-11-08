#include "Bureaucrat.hpp"
#include "Intern.hpp"

#define FORM_SH "Shrubbery"
#define FORM_RO "Robotomy"
#define FORM_PA "Pardon"

int main()
{
	Bureaucrat a("A", 2);
	Intern i;

	std::cout << a;

	try
	{
		AForm* form = i.makeForm(FORM_RO, "test1");
		std::cout << *form;
		a.signForm(*form);
		std::cout << *form;
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Intern can't make the form because " << e.what() << std::endl;
	}

	try
	{
		AForm* form = i.makeForm("No", "error");
		std::cout << *form;
		a.signForm(*form);
		std::cout << *form;
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Intern can't make the form because " << e.what() << std::endl;
	}

	//system("leaks intern");

	return (0);
}
