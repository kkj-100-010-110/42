#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& d);
	Dog& operator = (const Dog& d);
	~Dog();

	virtual void makeSound() const;
};

#endif