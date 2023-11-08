#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>
#include <cstdlib>

class Span
{
private:
	std::vector<int> m_container;
	unsigned int m_size;

private:
	Span();

public:
	Span(unsigned int n);
	Span(const Span& s);
	Span& operator = (const Span& s);
	~Span();

	void addNumber(int n);
	void addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	std::vector<int> getContainer() const;
	unsigned int getSize() const;
};

#endif
