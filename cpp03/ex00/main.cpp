

#include "ClapTrap.hpp"
#include <iostream>

void copy_test(void) {
  std::cout << "Copy testing starting" << std::endl;
  ClapTrap tono("rosado");
  ClapTrap tona(tono);

  std::cout << tono.get_name() << " first name" << std::endl;
  std::cout << tona.get_name() << " Second name" << std::endl;

  std::cout << "Changing the first name\n" << std::endl;
  tono.set_name("aluvina");
  std::cout
      << "Testing the names of the base and then copy to ensure deep copies"
      << std::endl;
  std::cout << tono.get_name() << " First name should be aluvina\n"
            << tona.get_name() << " Second name should still be rosado\n"
            << std::endl;

  std::cout << "Copy testing done\n" << std::endl;
}

void basic_test(void) {
  std::cout << "Basic testing done to class" << std::endl;
  ClapTrap robot("Eldorado");

  robot.attack("ElmenosDorado");
  robot.attack("ElmenosDorado");
  robot.beRepaired(5);
  robot.beRepaired(5);
  robot.beRepaired(5);
  robot.beRepaired(5);
  robot.takeDamage(20);
  robot.takeDamage(20);
  robot.attack("ElmenosDorado");
  robot.attack("ElmenosDorado");
  robot.attack("ElmenosDorado");
  robot.attack("ElmenosDorado");
  robot.attack("ElmenosDorado");
  robot.attack("ElmenosDorado");
  std::cout << "Basic testing done already\n" << std::endl;
}

int main() {
  basic_test();
  copy_test();

  return 0;
}
