#include "Boolean.hpp"

using namespace std;

int main()
{
	// ex00 & ex01

	// unsigned int a, b;

	// cout << "Enter two numbers : ";
	// cin >> a >> b;
	// cout << "You put the number" << endl;
	// cout << "num1 : " << a << " " << std::bitset<32> (a) << endl;
	// cout << "num2 : " << b << " " << std::bitset<32> (b) << endl;

	// cout << "Add two numbers : " << adder(a, b) << " " << std::bitset<32> (adder(a,b)) << endl;
	// cout << "multiply two numbers : " << multiplier(a, b) << " " << std::bitset<32> (multiplier(a,b)) << endl;

	// ex02

	cout << gray_code(0) << endl;
	cout << gray_code(1) << endl;
	cout << gray_code(2) << endl;
	cout << gray_code(3) << endl;
	cout << gray_code(4) << endl;
	cout << gray_code(5) << endl;
	cout << gray_code(6) << endl;
	cout << gray_code(7) << endl;
	cout << gray_code(8) << endl;
	cout << gray_code(9) << endl;

	// ex03

	std::cout << std::boolalpha << eval_formula("10&") << std::endl;
	std::cout << std::boolalpha << eval_formula("10|") << std::endl;
	std::cout << std::boolalpha << eval_formula("11>") << std::endl;
	std::cout << std::boolalpha << eval_formula("10=") << std::endl;
	std::cout << std::boolalpha << eval_formula("1011||=") << std::endl;

	return 0;
}