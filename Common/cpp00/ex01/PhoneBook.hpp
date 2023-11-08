#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <limits>
#include "Contact.hpp"

const int size = 8;
const int print_width = 10;

class PhoneBook
{
private:
	int count;
	std::string cmd;
	std::string print_str;
    Contact contacts[size];
	
    void add(void);
    void search(void);
	void print_search_result(int i);

public:
	PhoneBook();
	~PhoneBook();

	void start(void);
};

#endif
