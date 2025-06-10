#include <cstring>
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }
  for (int i = 1; i < argc; i++) {
    std::string tmp = argv[i];
    for (size_t j = 0; j < tmp.size(); j++)
      if (islower(tmp[j]))
        tmp[j] = toupper(tmp[j]);
    std::cout << tmp;
    if (i != argc - 1)
      std::cout << " ";
  }
  std::cout << std::endl;
  return 0;
}
