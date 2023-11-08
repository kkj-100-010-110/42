#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("A", 151);
		std::cout << a;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("B", 0);
		std::cout << b;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("C", 1);
		Bureaucrat d("D", 150);
		std::cout << c;
		std::cout << d;
		c.decrement();
		d.increment();
		std::cout << c;
		std::cout << d;
		c.increment();
		d.decrement();
		c.increment();
		d.decrement();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
