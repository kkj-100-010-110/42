#include "PhoneBook.hpp"

void PhoneBook::add(void)
{
	if (count < 8)
	{
		contacts[count].setContact();
		count++;
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
			contacts[i] = contacts[i + 1];
		contacts[count - 1].setContact();
	}
}

void PhoneBook::search(void)
{
	int input = 0;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|";
	std::cout << std::setw(print_width) << "INDEX" << "|";
	std::cout << std::setw(print_width) << "First Name" << "|";
	std::cout << std::setw(print_width) << "Last Name" << "|";
	std::cout << std::setw(print_width) << "Nickname" << "|";
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < size; i++)
		print_search_result(i);
	std::cout << std::endl;
	std::cout << std::endl;
	for (;;)
	{
		std::cout << "Please enter an index or number 9 to exit: ";
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof())
			return;
		if (std::cin.fail() || input < 1 || input > 9)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You may have entered the wrong index." << std::endl;
			continue;
		}
		else if (input == 9)
			break;
		else
		{
			if (input > count)
			{
				std::cout << "Empty on the index " << input << std::endl;
				break;
			}
			contacts[input - 1].print();
			break;
		}
	}
}

void PhoneBook::print_search_result(int i)
{
	std::cout << "|";
	std::cout << std::setw(print_width) << i + 1;
	std::cout << "|";
	std::cout << std::setw(print_width);
	if (contacts[i].getFirstName().length() <= print_width)
		std::cout << contacts[i].getFirstName();
	else
	{
		print_str = contacts[i].getFirstName();
		print_str.resize(print_width - 1);
		print_str += '.';
		std::cout << print_str;
	}
	std::cout << "|";
	std::cout << std::setw(print_width);
	if (contacts[i].getLastName().length() <= print_width)
		std::cout << contacts[i].getLastName();
	else
	{
		print_str = contacts[i].getLastName();
		print_str.resize(print_width - 1);
		print_str += '.';
		std::cout << print_str;
	}
	std::cout << "|";
	std::cout << std::setw(print_width);
	if (contacts[i].getNickname().length() <= print_width)
		std::cout << contacts[i].getNickname();
	else
	{
		print_str = contacts[i].getNickname();
		print_str.resize(print_width - 1);
		print_str += '.';
		std::cout << print_str;
	}
	std::cout << "|";
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

PhoneBook::PhoneBook()
	: count(0)
	, cmd("")
	, print_str("")
{}

PhoneBook::~PhoneBook()
{}

void PhoneBook::start(void)
{
	for (;;)
	{
		std::cout << std::endl;
		std::cout << "My Awesome PhoneBook" << std::endl;
		std::cout << std::endl;
		std::cout << "COMMANDS" << std::endl;
		std::cout << "--------" << std::endl;
		std::cout << "ADD     " << std::endl;
		std::cout << "SEARCH  " << std::endl;
		std::cout << "EXIT    " << std::endl;
		std::cout << "--------" << std::endl;
		std::cout << std::endl;
		std::cout << "Please enter a command: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You may have entered the command incorrectly." << std::endl;
			continue;
		}
		else if (cmd == "ADD")
			add();
		else if (cmd == "SEARCH")
			search();
		else if (cmd == "EXIT")
			break;
		else
		{
			std::cout << "You may have entered the command incorrectly." << std::endl;
			continue;
		}
	}
}
