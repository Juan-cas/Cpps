#include "support_foos.hpp"
#include <iostream>
#include <map>

int main(int argc, char **argv) {
  if (argc != 1) {
    std::cerr << std::endl;
  }
  std::map<std::string, float> dataBase;
  load_database("src/data.csv", dataBase);
  read_file(argv[1], dataBase);
}
