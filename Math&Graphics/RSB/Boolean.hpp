#ifndef BOOLEAN_HPP_
#define BOOLEAN_HPP_

#include <iostream>
#include <bitset>
#include <string>
#include <stack>

// ex00
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

// recursion
uint32_t adder(uint32_t a, uint32_t b)
{
	return b == 0 ? a : adder(a ^ b, (a & b) << 1);
}

// ex01
uint32_t multiplier(uint32_t a, uint32_t b)
{
	uint32_t result = 0;

	for (int i = 0; b != 0; b >>= 1, i++)
	{
		if (b & 1)
			result = adder(result, a << i);
	}

	return result;
}

// ex02
uint32_t gray_code(uint32_t n)
{
	return n ^ (n >> 1);
}

// ex03 - by stack
bool eval_formula(const std::string &formula)
{
	std::stack<unsigned int> st;
	char token;
	char symbol;
	unsigned int rightPredicate;
	unsigned int leftPredicate;

	for (int i = 0; i < formula.length(); i++)
	{
		token = formula.at(i);
		if (token == '0' || token == '1')
		{
			st.push(token - '0');
		}
		else if (token == '!')
		{
			if (st.empty())
			{
				std::cerr << "Not enough logical predicates." << std::endl;
				return false;
			}
			rightPredicate = st.top();
			st.pop();
			st.push(~rightPredicate);
		}
		else
		{
			if (st.size() < 2)
			{
				std::cerr << "Neither enough logical predicates." << std::endl;
				std::cerr << "nor right symbol." << std::endl;
				return false;
			}
			rightPredicate = st.top();
			st.pop();
			leftPredicate = st.top();
			st.pop();
			switch (token)
			{
			case '^':
				st.push(leftPredicate ^ rightPredicate);
				break;
			case '&':
				st.push(leftPredicate & rightPredicate);
				break;
			case '|':
				st.push(leftPredicate | rightPredicate);
				break;
			case '>':
				// st.push(leftPredicate | (~rightPredicate));
				st.push(leftPredicate | (!rightPredicate));
				break;
			case '=':
				// st.push((leftPredicate | (~rightPredicate)) & (rightPredicate | (~leftPredicate)));
				// st.push((leftPredicate & rightPredicate) | ((~leftPredicate) & (~rightPredicate)));
				st.push((leftPredicate & rightPredicate) | ((!leftPredicate) & (!rightPredicate)));
				break;
			default:
				std::cerr << "The symbol is invalid." << std::endl;
				return false;
			}
		}
	}
	if (st.size() != 1)
	{
		std::cerr << "Wrong formula." << std::endl;
		return false;
	}
	else
	{
		return st.top();
	}
}

// ex03

namespace AST
{
	class ASTNode
	{
		char element;
		ASTNode *right = nullptr;
		ASTNode *left = nullptr;

	public:
		ASTNode() { element = 0; }
		ASTNode(char e)
			: element(e)
		{ }
	};

	class AST : public ASTNode
	{
		ASTNode *head;
		std::string str;

	public:
		AST() { head = nullptr; }
		AST(const std::string &s)
			: head(nullptr), str(s)
		{ }

		void store()
		{
			for (auto it = str.begin(); it != str.end(); it++)
			{
				if (head == nullptr)
				{
					if (*it == '1' || *it == '0')
					{
					}
					else
					{
					}
				}
			}
		}

		
	};

	bool eval_formular(const std::string &formular)
	{
	}
}

#endif