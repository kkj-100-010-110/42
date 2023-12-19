#include "RSB.hpp"

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

	// cout << "Add two numbers : " << RSB::adder(a, b) << " " << std::bitset<32> (RSB::adder(a,b)) << endl;
	// cout << "multiply two numbers : " << RSB::multiplier(a, b) << " " << std::bitset<32> (RSB::multiplier(a,b)) << endl;

	// ex02

	// cout << RSB::gray_code(0) << endl;
	// cout << RSB::gray_code(1) << endl;
	// cout << RSB::gray_code(2) << endl;
	// cout << RSB::gray_code(3) << endl;
	// cout << RSB::gray_code(4) << endl;
	// cout << RSB::gray_code(5) << endl;
	// cout << RSB::gray_code(6) << endl;
	// cout << RSB::gray_code(7) << endl;
	// cout << RSB::gray_code(8) << endl;
	// cout << RSB::gray_code(9) << endl;

	// ex03

	// std::cout << std::boolalpha << RSB::eval_formula("10&") << std::endl;
	// std::cout << std::boolalpha << RSB::eval_formula("10|") << std::endl;
	// std::cout << std::boolalpha << RSB::eval_formula("11>") << std::endl;
	// std::cout << std::boolalpha << RSB::eval_formula("10=") << std::endl;
	// std::cout << std::boolalpha << RSB::eval_formula("1011||=") << std::endl;

	// tree test
	//PARSE::Tree t;
	// t.parse("A!!B!&!!C|", 0);
	// t.parse("AB&C|");
	// t.parse("AB&CD&|", 0);
	// t.print(2);
	// std::cout << std::endl;
	// t.print(1);
	// std::cout << std::endl;
	//std::cout << t.getCountLetter() << std::endl;
	// std::cout << t.getLetters() << std::endl;

	// ex04
	// RSB::print_truth_table("AB&C|");
	// RSB::print_truth_table("AB&CD&|");

	// ex05
	PARSE::Tree t;
	// t.parseEx05("AB^!");
	// //"AB&!"
	// //"AB|!"
	// //"AB>"
	// //"AB^"
	// //"AB="
	// //"AB|C&!"
	// t.printEx05();
	// std::cout << std::endl;
	// t.print();
	// std::cout << std::endl;
	
	// error check
	// std::cout << RSB::negation_normal_form("AB&!") << std::endl;
	// std::cout << RSB::negation_normal_form("AB|!") << std::endl;
	// std::cout << RSB::negation_normal_form("AB>") << std::endl;
	// std::cout << RSB::negation_normal_form("AB^") << std::endl;
	// std::cout << RSB::negation_normal_form("AB=") << std::endl;
	// std::cout << RSB::negation_normal_form("AB|C&!") << std::endl;
	// std::cout << RSB::negation_normal_form("A!!B!!|!") << std::endl;
	std::cout << RSB::negation_normal_form("AB>") << std::endl;
	std::cout << RSB::negation_normal_form("AB>C|") << std::endl;
	std::cout << RSB::negation_normal_form("AB>C|!") << std::endl;
	std::cout << RSB::negation_normal_form("AB>C|!D^") << std::endl;
	std::cout << RSB::negation_normal_form("AB>C|!D^!") << std::endl;

	return 0;
}