#include "Replace.hpp"


bool Replace::is_valid(void)
{
	if (m_filename == "" || m_s1 == "" || m_s2 == "")
	{
		std::cout << "Variables are not set yet." << std::endl;
		return false;
	}
	std::ifstream in(m_filename);
	if (in.fail())
	{
		std::cout << "No such file." << std::endl;
		return false;
	}
	std::stringstream ss;
	ss << in.rdbuf();
	if (ss.str() == "")
	{
		std::cout << "The file is empty." << std::endl;
		return false;
	}
	m_temp = ss.str();
	in.close();
	return true;
}

Replace::Replace()
	: m_filename(""), m_s1(""), m_s2(""), m_temp("")
{}

Replace::~Replace()
{}

void Replace::getData(const std::string& filename, const std::string& s1, const std::string& s2)
{
	m_filename = filename;
	m_s1 = s1;
	m_s2 = s2;
}

void Replace::replace(void)
{
	if (is_valid() == false)
	{
		std::cout << "Please, try again." << std::endl;
		return;
	}
	int pos = 0;
	std::ofstream out(m_filename + ".replace");
	if (out.fail())
	{
		std::cout << "Failed to write a file" << std::endl;
		return;
	}
	for (;;)
	{
		pos = m_temp.find(m_s1, pos);
		if (pos != static_cast<int>(std::string::npos))
		{
			m_temp.erase(pos, m_s1.length());
			m_temp.insert(pos, m_s2);
			pos += m_s2.length();
		}
		else
			break;
	}
	out << m_temp;
	out.close();
}
