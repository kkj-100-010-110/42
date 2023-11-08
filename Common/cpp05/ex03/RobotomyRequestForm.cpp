#include "RobotomyRequestForm.hpp"

/*******************************************************************************
 * Orthodox Canonical form													   *
 *******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", SIGN_ROBOTOMY, EXEC_ROBOTOMY)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf)
	: AForm(rrf)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, SIGN_ROBOTOMY, EXEC_ROBOTOMY)
{}

// assignment operator overloading unavailable
RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& rrf)
{
	(void)rrf;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

/*******************************************************************************
 * member function															   *
 *******************************************************************************/

void RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	canExecute(b);
	srand(time(NULL));
	std::cout << "Drrrrrrrrrr......" << std::endl;
	if (rand() % 2)
		std::cout << getName() << " became a robot." << std::endl;
	else
		std::cout << getName() << " fail to become a robot." << std::endl;
}
