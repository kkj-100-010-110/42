#include "RSB_bak.hpp"

// ex00 memo
// time complexity is O(n)
// while loop
// uint32_t adder(uint32_t a, uint32_t b)
// {
//     uint32_t carry;
//     while (b != 0)
//     {
//         carry = a & b;
//         a = a ^ b;
//         b = carry << 1;
//     }
//     return a;
// }
uint32_t RSB::adder(uint32_t a, uint32_t b)
{
	return b == 0 ? a : adder(a ^ b, (a & b) << 1);
}

// ex01
uint32_t RSB::multiplier(uint32_t a, uint32_t b)
{
	uint32_t result = 0;

	for (int i = 0; b != 0; b >>= 1, i++) {
		if (b & 1)
			result = adder(result, a << i);
	}

	return result;
}

// ex02
uint32_t RSB::gray_code(uint32_t n)
{
	return n ^ (n >> 1);
}

// ex03 - by tree
bool RSB::eval_formula(const std::string &formula)
{
	PARSE::ex03Tree tree;
	tree.parse(formula);

	return tree.getAnswer();
}

// ex03 - by stack
// bool RSB::eval_formula(const std::string &formula)
// {
// 	std::stack<unsigned int> st;
// 	char token;
// 	char symbol;
// 	unsigned int rightPredicate;
// 	unsigned int leftPredicate;

// 	for (int i = 0; i < formula.length(); i++) {
// 		token = formula.at(i);
// 		if (token == '0' || token == '1') {
// 			st.push(token - '0');
// 		} else if (token == '!') {
// 			if (st.empty()) {
// 				std::cerr << "Not enough logical predicates." << std::endl;
// 				return false;
// 			}
// 			rightPredicate = st.top();
// 			st.pop();
// 			st.push(~rightPredicate);
// 		} else {
// 			if (st.size() < 2) {
// 				std::cerr << "Neither enough logical predicates." << std::endl;
// 				std::cerr << "nor right symbol." << std::endl;
// 				return false;
// 			}
// 			rightPredicate = st.top();
// 			st.pop();
// 			leftPredicate = st.top();
// 			st.pop();
// 			switch (token) {
// 			case '^':
// 				st.push(leftPredicate ^ rightPredicate);
// 				break;
// 			case '&':
// 				st.push(leftPredicate & rightPredicate);
// 				break;
// 			case '|':
// 				st.push(leftPredicate | rightPredicate);
// 				break;
// 			case '>':
// 				// st.push(leftPredicate | (~rightPredicate));
// 				st.push(leftPredicate | (!rightPredicate));
// 				break;
// 			case '=':
// 				// st.push((leftPredicate | (~rightPredicate)) & (rightPredicate | (~leftPredicate)));
// 				// st.push((leftPredicate & rightPredicate) | ((~leftPredicate) & (~rightPredicate)));
// 				st.push((leftPredicate & rightPredicate) | ((!leftPredicate) & (!rightPredicate)));
// 				break;
// 			default:
// 				std::cerr << "The symbol is invalid." << std::endl;
// 				return false;
// 			}
// 		}
// 	}
// 	if (st.size() != 1) {
// 		std::cerr << "Wrong formula." << std::endl;
// 		return false;
// 	} else {
// 		return st.top();
// 	}
// }

void RSB::print_truth_table(const std::string &formula)
{
	PARSE::Tree t;
	t.parse(formula, 0);
	std::string variables = t.getLetters();
	std::string realFormula = t.getFormula(3);
	std::vector<std::vector<int>> table;
	table.resize(2 << variables.size() - 1);
	for (int j = 0; j < (2 << variables.size() - 1); j++) {
		int num = j;
		for (int i = 0; i < variables.size(); i++) {
			table[j].push_back(num & 1);
			num >>= 1;
		}
	}
	for (auto it = variables.begin(); it != variables.end(); it++)
		std::cout << "| " << *it << " ";
	std::cout << "| " << "=" << " |" << std::endl;
	for (auto it = variables.begin(); it != variables.end(); it++)
		std::cout << "|---";
	std::cout <<"|---|" << std::endl;
	for (int j = 0; j < (2 << variables.size() - 1); j++) {
		std::string copy = realFormula;
		for (int i = variables.size() - 1, k = 0; i >= 0; i--, k++) {
			std::cout << "| " << table[j].at(i) << " ";
			copy[copy.find(variables.at(k))] = table[j].at(i) + '0';
			if (i == 0) {
				std::cout << "| " << eval_formula(copy) << " |";
			}
		}
		std::cout << std::endl;
	}
}