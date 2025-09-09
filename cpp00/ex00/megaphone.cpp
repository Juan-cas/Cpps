#include <cstring>
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    std::string tmp = argv[i];
    int len = std::strlen(argv[i]);
    for (int i = 0; i < len; i++) {
      if (std::islower(tmp[i])) {
        tmp[i] = std::toupper(tmp[i]);
      }
    }
    std::cout << tmp;
  }
  std::cout << std::endl;
  return 0;
}
