#include "Templates.hpp"

int main() {
  int a = 10;
  int b = 28;

  std::cout << "the values are a:" << a << " and b:" << b << " is."
            << std::endl;

  std::cout << "the min is: " << min<int>(a, b) << std::endl;

  std::cout << "the max is: " << max<int>(a, b) << std::endl;

  swap<int>(a, b);

  std::cout << "\nthe values are a:" << a << " and b:" << b << " is."
            << std::endl;

  std::cout << "the min is: " << min<int>(a, b) << std::endl;

  std::cout << "the max is: " << max<int>(a, b) << std::endl;
}
