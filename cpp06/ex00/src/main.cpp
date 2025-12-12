#include "scalarConverter.hpp"

int main() {
  std::cout << "\ntest 1 being done:\n" << std::endl;
  std::string test1 = "nan";
  ScalarConverter::convert(test1);
  std::cout << "\ntest 2 being done:\n" << std::endl;
  std::string test2 = "-inf";
  ScalarConverter::convert(test2);
  std::cout << "\ntest 3 being done:\n" << std::endl;
  std::string test3 = "0";
  ScalarConverter::convert(test3);
  std::cout << "\ntest 4 being done:\n" << std::endl;
  std::string test4 = "25";
  ScalarConverter::convert(test4);
  std::cout << "\ntest 5 being done:\n" << std::endl;
  std::string test5 = "68";
  ScalarConverter::convert(test5);
  std::cout << "\ntest 6 being done:\n" << std::endl;
  std::string test6 = "75";
  ScalarConverter::convert(test6);
}
