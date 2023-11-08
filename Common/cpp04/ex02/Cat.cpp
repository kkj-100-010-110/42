#include "Cat.hpp"

/*******************************************************************************
 * Orthodox Canonical Form													   *
 *******************************************************************************/

Cat::Cat()
	: Animal()
{
	m_type = "Cat";
	m_brain = new Brain;
	std::cout << m_type << " constructor is called." << std::endl;
}

Cat::Cat(const Cat& c)
{
	m_type = c.m_type;
	m_brain = new Brain;
	for (int i = 0; i < 100; i++)
		m_brain->setIdea(c.m_brain->getIdea(i), i);
	std::cout << m_type << " copy constructor is called." << std::endl;
}

Cat& Cat::operator = (const Cat& c)
{
	if (this == &c)
		std::cout << "The parameter is assigned to itself." << std::endl;
	else
	{
		m_type = c.m_type;
		delete m_brain;
		m_brain = new Brain(*c.getBrain());
		std::cout << m_type << " is assigned." << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	delete m_brain;
	std::cout << m_type << " destructor is called." << std::endl;
}

/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

void Cat::makeSound() const { std::cout << "Meow~" << std::endl; }
Brain* Cat::getBrain() const { return m_brain; }
