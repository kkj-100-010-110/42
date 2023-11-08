#include "Dog.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

Dog::Dog()
	: Animal()
{
	m_type = "Dog";
	m_brain = new Brain;
	std::cout << m_type << " constructor is called." << std::endl;
}

Dog::Dog(const Dog& d)
{
	m_type = d.m_type;
	m_brain = new Brain;
	for (int i = 0; i < 100; i++)
		m_brain->setIdea(d.m_brain->getIdea(i), i);
	std::cout << m_type << " copy constructor is called." << std::endl;
}

Dog& Dog::operator = (const Dog& d)
{
	if (this == &d)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_type = d.m_type;
		delete m_brain;
		m_brain = new Brain(*d.getBrain());
		std::cout << m_type << " is assigned." << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	delete m_brain;
	std::cout << m_type << " destructor is called." << std::endl;
}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
Brain* Dog::getBrain() const { return m_brain; }
