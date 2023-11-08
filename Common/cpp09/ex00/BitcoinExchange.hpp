#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

class Bitcoin
{
private:
	std::map<std::string, float> m_db;
	std::string m_fname;

public:
	Bitcoin();
	Bitcoin(const Bitcoin& db);
	Bitcoin& operator = (const Bitcoin& db);
	~Bitcoin();

	void setDB(const std::string& db);
	void setFileName(const std::string& fname);
	void printDB();
	void processData();
	void printLine(const std::string& str);
	std::map<std::string, float>::iterator findExchange(const std::string& str);
	bool isValidDate(const std::string& str);
};

#endif
