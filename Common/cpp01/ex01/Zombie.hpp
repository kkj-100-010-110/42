#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string m_name;

public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void setName(std::string name);
	void announce();
};

#endif
