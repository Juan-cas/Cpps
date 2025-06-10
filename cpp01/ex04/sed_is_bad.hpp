#ifndef SED_IS_BAD_HPP
#define SED_IS_BAD_HPP

#include <cstdlib>
#include <string>

void write_file(const std::string &filename, const std::string &content);
std::string find_and_replace(const std::string &file_content, std::string &str1,
                             std::string &str2);
std::string read_file(const std::string &filename);

#endif // SED_IS_BAD_HPP
