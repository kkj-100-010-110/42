#include "BitcoinExchange.hpp"

/*******************************************************************************
 * Orthodox canonical form													   *
 *******************************************************************************/
Bitcoin::Bitcoin() { }
Bitcoin::Bitcoin(const Bitcoin& db)
{
	this->m_fname = db.m_fname;
	this->m_db = db.m_db;
}
Bitcoin& Bitcoin::operator = (const Bitcoin& db)
{
	this->m_fname = db.m_fname;
	this->m_db = db.m_db;
	return *this;
}
Bitcoin::~Bitcoin() { }


/*******************************************************************************
 * member functions															   *
 *******************************************************************************/

void Bitcoin::setDB(const std::string& db)
{
	size_t pos;
	float value;
	std::ifstream in(db.c_str());
	if (!in.good())
	{
		std::cerr << "Error: cannot open 'data.csv'" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	std::getline(in, line);
	while (std::getline(in, line))
	{
		pos = line.find(',');
		std::string key = line.substr(0, pos);
		value = std::atof(line.substr(pos+1).c_str());
		m_db[key] = value;
	}
	in.close();
}

void Bitcoin::setFileName(const std::string& fname)
{
	m_fname = fname;
}

void Bitcoin::printDB()
{
	for (std::map<std::string, float>::iterator it = m_db.begin(); it != m_db.end(); it++)
		std::cout << it->first << " => " << it->second << std::endl;
}

void Bitcoin::processData()
{
	std::ifstream in(m_fname.c_str());
	if (!in.good())
	{
		std::cerr << "Error: cannot open " << m_fname << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	std::getline(in, line);
	if (line != "date | value")
	{
		std::cerr << "Error: the first line should be 'date | value'" << std::endl;
		exit(EXIT_FAILURE);
	}
	while (std::getline(in, line))
		printLine(line);
	in.close();
}

void Bitcoin::printLine(const std::string& str)
{
	size_t pos = str.find('|');
	std::string date = str.substr(0, pos - 1);
	float value = std::atof(str.substr(pos+2).c_str());

	if (pos == std::string::npos || isValidDate(date) == false)
		std::cout << "Error: bad input => " << str << std::endl;
	else if (value < 0)
		std::cout << "Error: not a postive number." << std::endl;
	else if (value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
	{
		std::map<std::string, float>::iterator it = m_db.find(date);
		if (it == m_db.end())
			it = findExchange(date);
		if (it == m_db.begin())
			std::cout << "Error: bad input => " << str << std::endl;
		else
		{
			std::cout << date << " => " << value << " = ";
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << value * it->second << std::endl;
		}
	}
}

std::map<std::string, float>::iterator Bitcoin::findExchange(const std::string& str)
{
	std::map<std::string, float>::iterator it;

	for (it = m_db.begin(); it->first < str && it != m_db.end(); it++)
		;
	if (it == m_db.begin())
		return it;
	return --it;
}

bool Bitcoin::isValidDate(const std::string& str)
{
	int year, month, day;

	year = std::atoi(str.substr(0, 4).c_str());
	month = std::atoi(str.substr(5, 7).c_str());
	day = std::atoi(str.substr(8).c_str());
	if (year < 2009 || year > 2022)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12)
		return day > 31 || day < 1 ? false : true;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return day > 30 || day < 1 ? false : true;
	else
		return day > 28 || day < 1 ? false : true;
}
