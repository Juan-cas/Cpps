#include "sed_is_bad.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << "Please provide an infile, string1, string2" << std::endl;
    return (1);
  }
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  std::string tmp_file_content = read_file(argv[1]);
  if (tmp_file_content.empty()) {
    std::cout << "Failed to get data from file" << std::endl;
    exit(1);
  }
  tmp_file_content = find_and_replace(tmp_file_content, s1, s2);
  if (tmp_file_content.empty()) {
    std::cout << "Failed to replace anything" << std::endl;
    exit(1);
  }
  write_file("outfile.txt", tmp_file_content);
  return (0);
}
