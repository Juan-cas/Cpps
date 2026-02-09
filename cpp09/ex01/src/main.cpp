#include "RPN.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Error";
    return (1);
  }
  letsParseInput(argv[1]);
}
