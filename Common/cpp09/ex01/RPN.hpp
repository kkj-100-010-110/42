#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <list>

class Rpn
{
private:
	std::list<int> m_expression;
	std::string m_data;

public:
	Rpn();
	Rpn(const Rpn& expression);
	Rpn& operator = (const Rpn& expression);
	~Rpn();

	std::string getExpression(void) const;
	void setExpression(const std::string& data);
	void operation(void);
	int count(int n);
};

#endif
