#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <ctime>

#define SIGN_ROBOTOMY 72
#define EXEC_ROBOTOMY 45

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm& operator = (const RobotomyRequestForm& rrf);

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& rrf);
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();

	void execute(const Bureaucrat& b) const;
};

#endif
