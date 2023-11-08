#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string m_type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& wa);
	WrongAnimal& operator = (const WrongAnimal& wa);
	~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif
