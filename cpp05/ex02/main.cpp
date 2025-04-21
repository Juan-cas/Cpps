#include <cassert>
#include <iostream>
#include "tests.hpp"

int main() {

  std::cout << "\n== Starting tests ==" << std::endl;
 
  std::cout << "first batch of tests" << std::endl;
  tests_batch_1();

  std::cout << "second batch of tests" << std::endl;
  tests_batch_2();

  std::cout << "third batch of tests" << std::endl;
  tests_batch_3();

  std::cout << "\n== All tests finished ==" << std::endl;
  return 0;
}
