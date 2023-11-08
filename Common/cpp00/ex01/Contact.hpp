#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

enum contactIndex
{
	F, // first name
	L, // last name
	N, // nickname
	P, // phone number
	D, // darkest secret
	S  // size of contact
};

class Contact
{

private:
	std::string m_contactInfo[S];

public:
	Contact();
	~Contact();

	void setContact(void);
	void print(void);
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickname(void) const;
    std::string getPhoneNumber(void) const;
    std::string getDarkestSecret(void) const;
};

#endif
