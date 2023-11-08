#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

template <typename T>
typename T::const_iterator easyfind(T& container, int value)
{
	typename T::const_iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::runtime_error("Value Not Found");
	return iter;
}

#endif
