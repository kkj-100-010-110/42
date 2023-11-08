#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{}

Base* generate()
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Generate A" << std::endl;
			return new A;
		case 1:
			std::cout << "Generate B" << std::endl;
			return new B;
		case 2:
			std::cout << "Generate C" << std::endl;
			return new C;
		default:
			std::cerr << "Error on generating" << std::endl;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer to B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer to C" << std::endl;
	else
		std::cout << "None of A, B and C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference to A" << std::endl;
		static_cast<void>(a);
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Reference to B" << std::endl;
		static_cast<void>(b);
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Reference to C" << std::endl;
		static_cast<void>(c);
		return ;
	}
	catch (std::exception& e) {}
	std::cout << "None of A, B and C" << std::endl;
}
