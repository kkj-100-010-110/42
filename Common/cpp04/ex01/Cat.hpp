#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* m_brain;
public:
	Cat();
	Cat(const Cat& c);
	Cat& operator = (const Cat& c);
	~Cat();

	void makeSound() const;
	Brain* getBrain() const;
};

#endif
