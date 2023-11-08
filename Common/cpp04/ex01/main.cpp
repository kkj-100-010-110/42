#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	
	Dog* a = new Dog;
	Dog* b = new Dog;
	a->getBrain()->setIdea("test1", 0);
	a->getBrain()->setIdea("test2", 1);
	
	*b = *a;

	std::cout << a->getBrain() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (a->getBrain()->getIdea(i) == "")
			break;
		std::cout << a->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << b->getBrain() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (b->getBrain()->getIdea(i) == "")
			break;
		std::cout << b->getBrain()->getIdea(i) << std::endl;
	}


	delete a;
	delete b;
	delete j;
	delete i;

	// system("leaks animal");

	return 0;
}
