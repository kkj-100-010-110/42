#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "--------------------------------------------------\n";

//	MutantStack<int, std::list<int> > lst;
//
//	lst.push(5);
//	lst.push(17);
//
//	std::cout << lst.top() << std::endl;
//
//	lst.pop();
//
//	std::cout << lst.size() << std::endl;
//
//	lst.push(3);
//	lst.push(5);
//	lst.push(737);
//	//[...]
//	lst.push(0);
//
//	MutantStack<int>::iterator it = lst.begin();
//	MutantStack<int>::iterator ite = lst.end();
//	++it;
//	--it;
//	while (it != ite)
//	{
//		std::cout << *it << std::endl;
//		++it;
//	}
//	std::stack<int> s(lst);
//
//	std::cout << "--------------------------------------------------\n";
//
//	MutantStack<int, std::vector<int> > v;
//
//	v.push(5);
//	v.push(17);
//
//	std::cout << v.top() << std::endl;
//
//	v.pop();
//
//	std::cout << v.size() << std::endl;
//
//	v.push(3);
//	v.push(5);
//	v.push(737);
//	//[...]
//	v.push(0);
//
//	MutantStack<int>::iterator it = v.begin();
//	MutantStack<int>::iterator ite = v.end();
//	++it;
//	--it;
//	while (it != ite)
//	{
//		std::cout << *it << std::endl;
//		++it;
//	}
//	std::stack<int> s(v);
//	return 0;
}
