#ifndef SED_IS_BAD_HPP
#define SED_IS_BAD_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

void	write_file(const string &filename, const string &content);
string	find_and_replace(const string &file_content, string &str1, string &str2);
string	read_file(const string &filename);


#endif //SED_IS_BAD_HPP
