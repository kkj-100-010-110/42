#include "Contact.hpp"

namespace text
{
	std::string messages[S] = { "First name: ",
								"Last name: ",
								"Nickname: ",
								"Phone number: ",
								"Darkest Secret: " };
}

Contact::Contact()
{
	for (int i = 0; i < S; i++)
		m_contactInfo[i] = "";
}

Contact::~Contact()
{}

void Contact::setContact(void)
{
	for (int idx = 0; idx < S; idx++)
	{
		do
		{
			std::cout << "Please enter your " << text::messages[idx];
			std::getline(std::cin, m_contactInfo[idx]);
			if (std::cin.eof())
				return;
		} while (m_contactInfo[idx] == "");
	}
}

void Contact::print(void)
{
	for (int i = 0; i < S; i++)
		std::cout << text::messages[i] << m_contactInfo[i] << std::endl;
}

std::string Contact::getFirstName(void)		const { return this->m_contactInfo[F]; }
std::string Contact::getLastName(void)		const { return this->m_contactInfo[L]; }
std::string Contact::getNickname(void)		const { return this->m_contactInfo[N]; }
std::string Contact::getPhoneNumber(void)	const { return this->m_contactInfo[P]; }
std::string Contact::getDarkestSecret(void)	const { return this->m_contactInfo[D]; }
