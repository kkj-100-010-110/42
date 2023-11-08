#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("A", 150);
		Bureaucrat b("B", 1);
		Form f("F", 50, 50);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << f << std::endl;

		a.signForm(f);
		std::cout << std::endl;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		std::cout << std::endl;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << f << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	
	return (0);
}
