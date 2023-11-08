#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain& b);
	Brain& operator = (const Brain& b);
	~Brain();

	void setIdea(const std::string& idea, unsigned int idx);
	std::string getIdea(unsigned int idx) const;
};

#endif
