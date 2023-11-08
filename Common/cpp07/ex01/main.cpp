#include "iter.hpp"

template <typename T>
void print(const T& e)
{
	std::cout << e << " ";
}

int main()
{
	int arrInt[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::string arrStr[3] = { "Gyeong", "Ju", "Kim" };

	iter(arrStr, 3, print);
	std::cout << "\n";
	iter(arrInt, 10, print);
	std::cout << "\n";

	return 0;
}
