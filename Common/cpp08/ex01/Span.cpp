#include "Span.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

Span::Span()
	: m_container(0), m_size(0)
{}

Span::Span(unsigned int n)
	: m_size(n)
{
	m_container.reserve(n);
}

Span::Span(const Span& s)
{
	m_size = s.getSize();
	m_container = s.getContainer();
}

Span& Span::operator = (const Span& s)
{
	if (this == &s)
		return *this;
	if (m_container.capacity() != s.getContainer().capacity())
	{
		std::vector<int> v(s.getContainer().capacity());
		m_container.swap(v);
		m_container = s.getContainer();
	}
	m_container = s.getContainer();
	return *this;
}

Span::~Span()
{}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

void Span::addNumber(int n)
{
	if (m_container.capacity() == m_container.size())
		throw std::length_error("Size over");
	else
		m_container.push_back(n);
}

void Span::addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	if (static_cast<long>(m_container.capacity() - m_container.size()) >= std::distance(begin, end))
		m_container.insert(m_container.begin(), begin, end);
	else
		throw std::length_error("Size over");
}

unsigned int Span::shortestSpan() const
{
	if (m_container.size() < 2)
		throw std::length_error("No Span Found");
	else
	{
		std::vector<int> temp = m_container;
		std::sort(temp.begin(), temp.end());
		std::vector<int> diff(temp);
		unsigned int min = *std::max_element(std::begin(temp), std::end(temp));
		std::adjacent_difference(std::begin(diff), std::end(diff), std::begin(diff));
		for (unsigned int i = 1; i < diff.size(); ++i)
		{
			if (min > static_cast<unsigned int>(std::abs(diff[i])))
				min = static_cast<unsigned int>(std::abs(diff[i]));
		}
		return min;
	}
}

unsigned int Span::longestSpan() const
{
	if (m_container.size() < 2)
		throw std::length_error("No Span Found");
	return *std::max_element(m_container.begin(), m_container.end()) - *std::min_element(m_container.begin(), m_container.end());
}

std::vector<int> Span::getContainer() const { return m_container; }

unsigned int Span::getSize() const { return m_size; }
