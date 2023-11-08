#ifndef UTILE_HPP
# define UTILE_HPP

#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> split(const std::string &str, const std::string &delimiters);
std::vector<std::string> ft_split_join_param(const std::string &str, const std::string &delimiters);
bool ft_check_valid(const char c);
std::string ft_itostring(int i);
#endif
