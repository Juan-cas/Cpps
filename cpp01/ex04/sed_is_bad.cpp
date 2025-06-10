#include "sed_is_bad.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

std::string find_and_replace(const std::string &file_content, std::string &str1,
                             std::string &str2) {
  std::string result;
  size_t pos = 0;
  size_t prev_pos = 0;
  while ((pos = file_content.find(str1, prev_pos)) != std::string::npos) {
    result.append(file_content, prev_pos, pos - prev_pos);
    result.append(str2);
    prev_pos = pos + str1.length();
  }
  result.append(file_content, prev_pos, std::string::npos);
  return (result);
};

std::string read_file(const std::string &filename) {
  if (filename.empty()) {
    std::cout << "Please Input a correct infile filename" << std::endl;
    exit(1);
  }
  std::ifstream infile;
  infile.open(filename.c_str());
  if (!infile.is_open()) {
    std::cout << "Please check infile permisions" << std::endl;
    exit(1);
  }
  std::string line;
  std::string file_contents;
  while (getline(infile, line))
    file_contents += line + '\n';
  infile.close();
  if (file_contents.empty()) {
    std::cout << "file is empty" << std::endl;
    exit(1);
  }
  return (file_contents);
}

void write_file(const std::string &filename, const std::string &content) {
  if (filename.empty()) {
    std::cout << "Please input a correct outfile filename";
    exit(1);
  }
  std::ofstream outfile;
  outfile.open(filename.c_str());
  if (!outfile.is_open()) {
    std::cout << "Please check outfile permissions" << std::endl;
    exit(1);
  }
  outfile << content;
  outfile.close();
}
