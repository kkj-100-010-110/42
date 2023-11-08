#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/**************************************************************************************************
 * Replace : it opens a file and copies its content into a new file replacing s1 with s2 on it.   *
 **************************************************************************************************/

class Replace
{
private:
	std::string m_filename;
	std::string m_s1;
	std::string m_s2;
	std::string m_temp;

	bool is_valid(void);

public:
	Replace();
	~Replace();

	void getData(const std::string& filename, const std::string& s1, const std::string& s2);
	void replace(void);
};

#endif
