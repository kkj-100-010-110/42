#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "empty";
	std::cout << "Brain default constructor is called." << std::endl;
}

Brain::Brain(const Brain& b)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
	std::cout << "Brain copy constructor is called." << std::endl;
}

Brain& Brain::operator = (const Brain& b)
{
	if (this == &b)
		std::cout << "The parameter is assigned to itself" << std::endl;
	else
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = b.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called" << std::endl;
}

void Brain::setIdea(const std::string& idea, unsigned int idx)
{
	if (idx >= 100)
		std::cout << "You put the wrong index." << std::endl;
	ideas[idx] = idea;
}

std::string Brain::getIdea(unsigned int idx) const
{
	if (idx >= 100)
		std::cout << "You put the wrong index." << std::endl;
	return ideas[idx];
}
