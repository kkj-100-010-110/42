#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base* a = new A;
	Base* b = new B;
	Base* c = new C;
	Base* base = new Base;

	Base* g = generate();
	identify(g);
	identify(a);
	identify(b);
	identify(c);
	identify(base);
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*base);

	delete a;
	delete b;
	delete c;
	delete base;
	delete g;

	return 0;
}
