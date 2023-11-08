#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{
private:
	const std::string m_name;
	int m_grade;

private:
	Bureaucrat& operator = (const Bureaucrat& b);

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& b);
	Bureaucrat(const std::string& name, const int& grade);
	~Bureaucrat();

	void increment();
	void decrement();
	const std::string& getName() const;
	int getGrade() const;
	void signForm(const AForm& f) const;
	void executeForm(AForm const &f) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& b);

#endif
