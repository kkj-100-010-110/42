#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
public:
	MutantStack()
	{}
	MutantStack(const MutantStack& m)
	{
		*this = m;
	}
	MutantStack& operator = (const MutantStack& m)
	{
		if (this != &m)
			*this = m;
		return *this;
	}
	~MutantStack()
	{}

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_iterator cbegin() const { return this->c.cbegin(); }
	const_iterator cend() const { return this->c.cend(); }

	const_iterator crbegin() const { return this->c.crbegin(); }
	const_iterator crend() const { return this->c.crend(); }
};

#endif
