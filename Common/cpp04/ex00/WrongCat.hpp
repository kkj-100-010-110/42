#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& wc);
	WrongCat& operator = (const WrongCat& wc);
	~WrongCat();

	void makeSound() const;
};

#endif
