#ifndef INTER_HPP
#define INTER_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& i);
	Intern& operator = (const Intern& i);
	~Intern();

	AForm* create_shrubbery(const std::string& target);
	AForm* create_robotomy(const std::string& target);
	AForm* create_pardon(const std::string& target);

	AForm* makeForm(const std::string& form, const std::string& target);
	

	class NoFormException : public std::exception
	{
		const char* what() const throw();
	};
};

#endif
