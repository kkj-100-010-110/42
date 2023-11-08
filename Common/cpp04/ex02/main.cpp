#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	//const Animal* a = new Animal(); // abstract class cannot be instantiated

	Animal *animalArr[10];
	for (int i = 0; i < 5; i++)
		animalArr[i] = new Cat;
	for (int i = 5; i < 10; i++)
		animalArr[i] = new Dog;
	for (int i = 0; i < 10; i++)
		animalArr[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete animalArr[i];

	delete j;//should not create a leak 
	delete i;

	// system("leaks animal");

	return 0;
}
