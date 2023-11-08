#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string m_name;
	bool m_isSigned;
	const int m_requiredSign;
	const int m_requiredExecute;

private:
	AForm& operator = (const AForm& f);

public:
	AForm();
	AForm(const AForm& f);
	AForm(const std::string& name, const int sign, const int execute);
	virtual ~AForm();

	const std::string& getName() const;
	bool getIsSigned() const;
	const int& getRequiredSign() const;
	const int& getRequiredExecute() const;

	void beSigned(const Bureaucrat& b);
	void canExecute(const Bureaucrat& b) const;

	virtual void execute(const Bureaucrat& b) const = 0;

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

	class NotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class FileOpenException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream& operator << (std::ostream& out, const AForm& f);

#endif
