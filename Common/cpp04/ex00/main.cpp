#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();

	Animal *animalArr[10];
	for (int i = 0; i < 5; i++)
		animalArr[i] = new Cat;
	for (int i = 5; i < 10; i++)
		animalArr[i] = new Dog;
	for (int i = 0; i < 10; i++)
		animalArr[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete animalArr[i];

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	std::cout << l->getType() << " " << std::endl;
	l->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;

	// system("leaks animal");
}
