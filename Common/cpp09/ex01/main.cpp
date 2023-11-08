#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		throw std::invalid_argument("error: bad arguments");
	Rpn expr;
	expr.setExpression(argv[1]);
	expr.operation();

	return 0;
}
