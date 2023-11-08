#include "RPN.hpp"

/*******************************************************************************
 *  Orthodox canonical form													   *
 ******************************************************************************/
Rpn::Rpn(){}

Rpn::Rpn(const Rpn& expression)
{
	m_data = expression.m_data;
}

Rpn& Rpn::operator = (const Rpn& expression)
{
	m_data = expression.m_data;
	return *this;
}

Rpn::~Rpn(){}


/*******************************************************************************
 *  Member functions														   *
 ******************************************************************************/

std::string Rpn::getExpression(void) const { return m_data; }

void Rpn::setExpression(const std::string& data) { m_data = data; }

void Rpn::operation()
{
	int right_operand, left_operand;

	for (int i = 0; i < static_cast<int>(m_data.size()); i++)
	{
		if (m_data[i] == '-' && (m_data[i+1] >= '0' && m_data[i+1] <= '9'))
		{
			m_expression.push_back(atoi(m_data.substr(i).c_str()));
			i += count(m_expression.back() * -1);
		}
		else if (m_data[i] >= '0' && m_data[i] <= '9')
		{
			if (m_data[i+1] >= '0' && m_data[i+1] <= '9')
				throw std::domain_error("the number is greater than 10");
			m_expression.push_back(m_data[i] - 48);
		}
		else if (m_data[i] == '+' || m_data[i] == '-' || m_data[i] == '*' || m_data[i] == '/')
		{
			if (m_expression.size() < 2)
				throw std::logic_error("not enough operands");
			right_operand = m_expression.back();
			m_expression.pop_back();
			left_operand = m_expression.back();
			m_expression.pop_back();
			switch (m_data[i])
			{
				case '+':
					m_expression.push_back(left_operand + right_operand);
					break;
				case '*':
					m_expression.push_back(left_operand * right_operand);
					break;
				case '-':
					m_expression.push_back(left_operand - right_operand);
					break;
				case '/':
					m_expression.push_back(left_operand / right_operand);
					break;
			}
		}
	}
	if (m_expression.size() != 1)
		throw std::logic_error("either empty or left more than two in list");
	std::cout << m_expression.back() << std::endl;
}

int Rpn::count(int n)
{
	int i;
	for (i = 0; n >= 10; i++)
		n /= 10;
	return i + 1;
}
