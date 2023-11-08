#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat a("A", 2);
	Bureaucrat b("B", 139);
	Bureaucrat c("C", 148);
	AForm* f = new ShrubberyCreationForm("test");

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	a.signForm(*f);
	std::cout << *f << std::endl;
	a.executeForm(*f);
	f->execute(a);

	b.signForm(*f);
	std::cout << *f << std::endl;
	b.executeForm(*f);

	c.signForm(*f);
	std::cout << *f << std::endl;
	c.executeForm(*f);

	return (0);
}
