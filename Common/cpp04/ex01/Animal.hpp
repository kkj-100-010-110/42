#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string m_type;

public:
	Animal();
	Animal(const Animal& a);
	Animal& operator = (const Animal& a);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif
