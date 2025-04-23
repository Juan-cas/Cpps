#include "harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void Harl::debug() {
  std::cout << "[ DEBUG ]\nI love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special"
            << "-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
  std::cout
      << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You "
         "didn’t put "
      << "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning() {
  std::cout
      << "[ WARNING ]\n"
      << "I think I deserve to have some extra bacon for free.\n I’ve been "
         "coming for "
      << "years whereas you started working here since last month."
      << std::endl;
}

void Harl::error() {
  std::cout
      << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now."
      << std::endl;
}

void Harl::complain(std::string str) {
  std::string str_find[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int i = -1;
  while (++i < 4) {
    if (str == str_find[i])
      break;
  }
  switch (i) {
  case 0:
    this->debug();
  case 1:
    this->info();
  case 2:
    this->warning();
  case 3:
    this->error();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]" << '\n'
              << std::endl;
    break;
  }
}
