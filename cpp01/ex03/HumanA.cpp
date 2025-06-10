#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <ostream>

HumanA::HumanA(std::string name, Weapon &type) : name(name), weapon(type) {}

void HumanA::attack() {
  std::cout << this->name << " attacks with their " << this->weapon.getType()
            << std::endl;
}
