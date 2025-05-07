#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
  

  DiamondTrap *dt = new DiamondTrap("Diamy");
  dt->get_name();
  dt->whoami();
  dt->attack("a sturdy wall");
  dt->highFivesdGuys();
  dt->guardGate();
  dt->get_ep();
  dt->beRepaired(10);
  dt->get_ep();
  delete dt;
  return 0;
}
