#include "harl.hpp"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "Please input a parameter" << std::endl;
  }
  Harl harl;

  int i = 1;
  while (argv[i]) {
    harl.complain(argv[i]);
    i++;
  }
  return (0);
}
