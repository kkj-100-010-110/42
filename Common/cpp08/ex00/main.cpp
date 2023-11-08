#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main()
{
	int i;

	std::vector<int> v1;
	std::vector<int> v2;
	std::list<int> l1;
	std::list<int> l2;
	std::deque<int> d1;
	std::deque<int> d2;

	for (i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i);
		l1.push_back(i);
		l2.push_back(i);
		d1.push_back(i);
		d2.push_back(i);
	}
	for (i = 0; i < 20; i++)
	{
		v2.push_back(i);
		l2.push_back(i);
		d2.push_back(i);
	}

	std::vector<int> v5(v1);
	std::cout << "vector5 : " << *(easyfind(v5, 6)) << "\n";
	try
	{
		std::cout << "vector1: " << *(easyfind(v1, 4)) << '\n';
		std::cout << "list1: " << *(easyfind(l1, 9)) << '\n';
		std::cout << "deque1: " << *(easyfind(d1, 9)) << '\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "vector1: " << *(easyfind(v1, 19)) << '\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "list1: " << *(easyfind(l1, 19)) << '\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "deque1: " << *(easyfind(d1, 19)) << '\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "vector2: " << *(easyfind(v2, 9)) << '\n';
		std::cout << "list2: " << *(easyfind(l2, 9)) << '\n';
		std::cout << "deque2: " << *(easyfind(d2, 9)) << '\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "vector2: " << *(easyfind(v2, 19)) << '\n';
		std::cout << "list2: " << *(easyfind(l2, 19)) << '\n';
		std::cout << "deque2: " << *(easyfind(d2, 20)) << '\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
