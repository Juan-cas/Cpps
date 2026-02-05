#include "support_foos.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>

static std::string trim(const std::string &s) {
  size_t start = s.find_first_not_of(" \t");
  size_t end = s.find_last_not_of(" \t");

  if (start == std::string::npos)
    return "";

  return s.substr(start, end - start + 1);
}

float boundChecker(std::map<std::string, float> &dataBase,
                   std::string preline) {

  mapIt it = dataBase.lower_bound(preline);
  if (it != dataBase.end() && it->first == preline)
    return it->second;

  if (it == dataBase.begin())
    throw std::runtime_error("No earlier date found");

  --it;
  return it->second;
}

void read_file(const char *filename, std::map<std::string, float> &dataBase) {
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  std::string line;
  bool firstline = true;

  while (std::getline(infile, line)) {
    // ----- skip header -----
    if (firstline) {
      firstline = false;
      continue;
    }

    // ----- empty line -----
    if (line.empty())
      continue;

    // ----- delimiter check -----
    size_t pos = line.find('|');
    if (pos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string preline = trim(line.substr(0, pos));
    std::string postline = trim(line.substr(pos + 1));

    // ----- validation -----
    if (checkDateValues(preline))
      continue;
    if (checkAmountValues(postline))
      continue;

    try {
      float rate = boundChecker(dataBase, preline);
      float amount = std::atof(postline.c_str());

      std::cout << std::setprecision(4) << preline << " => " << postline
                << " = " << (amount * rate) << std::endl;
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }

  infile.close();
}

bool checkDateValues(std::string preline) {
  std::istringstream ss(preline);

  char separator;
  int year, month, day;
  ss >> year >> separator >> month >> separator >> day;
  if (year < 2009) {
    std::cerr << "Error: bad input => " << preline << std::endl;
    return true;
  }
  if (month < 1 || month > 12) {
    std::cerr << "Error: bad input => " << preline << std::endl;
    return true;
  }
  int monthsDays[12] = {30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (day < 1 || day > monthsDays[month - 1]) {
    std::cerr << "Error: bad input => " << preline << std::endl;
    return true;
  }
  return false;
}

bool checkAmountValues(std::string postline) {
  std::istringstream ss(postline);

  long amountOfBtc;
  ss >> amountOfBtc;

  if (amountOfBtc < 0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return true;
  }
  if (amountOfBtc > 1000) {
    std::cerr << "Error: too large a number." << std::endl;
    return true;
  }
  return false;
}

void load_database(const char *filename,
                   std::map<std::string, float> &dataBase) {
  std::ifstream infile;
  infile.open(filename);
  if (!infile.is_open()) {
    std::cerr << "Please check infile permisions" << std::endl;
    exit(1);
  }
  std::string line;
  std::string value;
  bool firstline = true;
  while (getline(infile, line)) {
    if (firstline == false) {
      value = line.substr(line.find(',') + 1);
      dataBase[line.substr(0, line.find(','))] = std::atof(value.c_str());
    }
    firstline = false;
  }
  infile.close();
}
