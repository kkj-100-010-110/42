#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe<int> v;
	PmergeMe<int, std::deque<int> > d;

	if (argc < 2)
		throw std::invalid_argument("wrong number of arguments");

	for (int i = 1; i < argc; i++)
	{
		v.push_back(atoi(argv[i]));
		d.push_back(atoi(argv[i]));
		if (v[i-1] <= 0)
			throw std::domain_error("not positive integer number");
	}

	std::cout << "Before\t: ";

	v.print();

	v.sort();

	d.sort();

	std::cout << "After\t: ";

	v.print();

	v.printTimeType();
	d.printTimeType();

	return 0;
}
