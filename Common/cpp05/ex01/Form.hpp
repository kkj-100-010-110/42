#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string m_name;
	bool m_isSigned;
	const int m_requiredSign;
	const int m_requiredExecute;

private:
	Form& operator = (const Form& f);

public:
	Form();
	Form(const Form& f);
	Form(const std::string& name, const int sign, const int execute);
	~Form();

	const std::string& getName() const;
	bool getIsSigned() const;
	const int& getRequiredSign() const;
	const int& getRequiredExecute() const;
	void beSigned(const Bureaucrat& b);

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

std::ostream& operator << (std::ostream& out, const Form& f);

#endif
